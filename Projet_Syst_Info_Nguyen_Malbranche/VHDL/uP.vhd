library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.std_logic_unsigned.ALL;
use IEEE.std_logic_arith.ALL;
use IEEE.numeric_std.all;

entity uP is
    Port ( CLK : in STD_LOGIC;
           RST : in STD_LOGIC;
           QA : out STD_LOGIC_VECTOR (7 downto 0);
           QB : out STD_LOGIC_VECTOR (7 downto 0));
end uP;


 --------------------------------------------------------LES INSTRUCTIONS --------------------------------------------------------
--00 NOP
--01 ADD
--02 MUL
--03 SOU
--04 DIV non implémenté dans ALU
--05 COP
--06 AFC
--07 LOAD
--08 STORE
--09 JMP line_to_jump_to
--0A JMF line_to_jump_to @to_check  à implémenter





 ----------------------------------------------------------------------------------------------------------------------------------

architecture Behavioral of uP is
    
 --------------------------------------------------------components --------------------------------------------------------
    
    component Compteur_8bits is
    Port ( CLK : in STD_LOGIC;
           RST : in STD_LOGIC;
           LOAD : in STD_LOGIC;
           SENS : in STD_LOGIC;
           EN : in STD_LOGIC;
           Din : in STD_LOGIC_VECTOR (7 downto 0);
           Dout : out STD_LOGIC_VECTOR (7 downto 0));
    end component;
    
    component Memoire_des_Instructions is
    Port ( adresse : in STD_LOGIC_VECTOR (7 downto 0);
           CLK : in STD_LOGIC;
           OUTPUT : out STD_LOGIC_VECTOR (31 downto 0));
    end component;
    
    component Banc_Registre_Real is
    Port ( a_A : in STD_LOGIC_VECTOR (3 downto 0);
           a_B : in STD_LOGIC_VECTOR (3 downto 0);
           a_W : in STD_LOGIC_VECTOR (3 downto 0);
           W : in STD_LOGIC;
           DATA : in STD_LOGIC_VECTOR (7 downto 0);
           RST : in STD_LOGIC;
           CLK : in STD_LOGIC;
           QA : out STD_LOGIC_VECTOR (7 downto 0);
           QB : out STD_LOGIC_VECTOR (7 downto 0));
    end component;
    
    component ALU is
    Port ( A : in STD_LOGIC_VECTOR (7 downto 0);
           B : in STD_LOGIC_VECTOR (7 downto 0);
           Operation : in STD_LOGIC_VECTOR (2 downto 0);
           S : out STD_LOGIC_VECTOR (7 downto 0);
           C : out STD_LOGIC;
           O : out STD_LOGIC;
           N : out STD_LOGIC);
    end component;
    
    component Memoire_des_Donnees is
    Port ( adresse : in STD_LOGIC_VECTOR (7 downto 0);
           INPUT : in STD_LOGIC_VECTOR (7 downto 0);
           RW : in STD_LOGIC;
           RST : in STD_LOGIC;
           CLK : in STD_LOGIC;
           OUTPUT : out STD_LOGIC_VECTOR (7 downto 0));
    end component;
    
    component Pipeline is
    Port ( a_in : in STD_LOGIC_VECTOR (7 downto 0);
           b_in : in STD_LOGIC_VECTOR (7 downto 0);
           c_in : in STD_LOGIC_VECTOR (7 downto 0);
           op_in : in STD_LOGIC_VECTOR (7 downto 0);
           a_out : out STD_LOGIC_VECTOR (7 downto 0);
           b_out : out STD_LOGIC_VECTOR (7 downto 0);
           c_out : out STD_LOGIC_VECTOR (7 downto 0);
           op_out : out STD_LOGIC_VECTOR (7 downto 0);
           CLK : in STD_LOGIC);
    end component;
    
    component Alea_Detector is
    Port ( LI_op : in STD_LOGIC_VECTOR (7 downto 0);
           DI_op : in STD_LOGIC_VECTOR (7 downto 0);
           EX_op : in STD_LOGIC_VECTOR (7 downto 0);
           LI_b : in STD_LOGIC_VECTOR (7 downto 0);
           LI_c : in STD_LOGIC_VECTOR (7 downto 0);
           DI_a : in STD_LOGIC_VECTOR (7 downto 0);
           EX_a : in STD_LOGIC_VECTOR (7 downto 0);
           alea : out STD_LOGIC);
    end component;
 --------------------------------------------------------internal signals --------------------------------------------------------
    
    --compteur_8bits
    signal sLOAD : std_logic := '0'; --on mettra à 1 quand on aura des JUMP
    signal sSENS : std_logic := '0'; --compte en positif
    signal sEN : std_logic := '0'; --is enabled
    signal sDin : std_logic_vector (7 downto 0) := (others => '0'); --we will load the value of JUMP
    signal sCompteur : std_logic_vector (7 downto 0);
    
    --memoire des instructions
    signal sInstructions : std_logic_vector (31 downto 0);
    
    --banc des registres
    signal sW : std_logic; 
    signal sQA : std_logic_vector (7 downto 0) ;
    signal sQB : std_logic_vector (7 downto 0);

    --alu
    signal sOperation_Alu : std_logic_vector (2 downto 0);
    signal sResultat_Alu : std_logic_vector (7 downto 0);
    signal sFlag_Unused : std_logic;

    --mémoire des données
    signal sOutput_Data_Memory : std_logic_vector (7 downto 0);
    signal sRW_Data_Memory : std_logic;

    --empty signal
    signal sEmpty : std_logic_vector (7 downto 0);

    --alea signal
    signal sAlea : std_logic;
    
 --------------------------------------------------------pipeline--------------------------------------------------------
    signal sPipeLI_DI_op_in : std_logic_vector (7 downto 0) := (others => '0');      
    signal sPipeLI_DI_a_out : std_logic_vector (7 downto 0) := (others => '0');
    signal sPipeLI_DI_b_out : std_logic_vector (7 downto 0) := (others => '0');
    signal sPipeLI_DI_c_out : std_logic_vector (7 downto 0) := (others => '0');
    signal sPipeLI_DI_op_out : std_logic_vector (7 downto 0) := (others => '0');


    signal sPipeDI_EX_a_out : std_logic_vector (7 downto 0) := (others => '0');
    signal sPipeDI_EX_b_out : std_logic_vector (7 downto 0) := (others => '0');
    signal sPipeDI_EX_c_out : std_logic_vector (7 downto 0) := (others => '0');
    signal sPipeDI_EX_op_out : std_logic_vector (7 downto 0);


    signal sPipeEX_Mem_a_out : std_logic_vector (7 downto 0) := (others => '0');
    signal sPipeEX_Mem_b_out : std_logic_vector (7 downto 0) := (others => '0');
    signal sPipeEX_Mem_c_out : std_logic_vector (7 downto 0) := (others => '0');
    signal sPipeEX_Mem_op_out : std_logic_vector (7 downto 0) := (others => '0');


    signal sPipeMem_RE_a_out : std_logic_vector (7 downto 0) := (others => '0');
    signal sPipeMem_RE_b_out : std_logic_vector (7 downto 0) := (others => '0');
    signal sPipeMem_RE_c_out : std_logic_vector (7 downto 0) := (others => '0');
    signal sPipeMem_RE_op_out : std_logic_vector (7 downto 0) := (others => '0');
    

 --------------------------------------------------------multiplexers--------------------------------------------------------
    signal sMuxBdR : std_logic_vector (7 downto 0);     
    signal sMuxAlu : std_logic_vector (7 downto 0);    
    signal sMuxDataMem_Input : std_logic_vector (7 downto 0);      
    signal sMuxDataMem_Output : std_logic_vector (7 downto 0);     

begin


 --------------------------------------------------------component connections  --------------------------------------------------------
    PipeLI_DI : Pipeline
        port map (
           a_in => sInstructions(23 downto 16),
           b_in => sInstructions(15 downto 8),
           c_in => sInstructions(7 downto 0),
           op_in => sPipeLI_DI_op_in, 
           a_out => sPipeLI_DI_a_out,
           b_out => sPipeLI_DI_b_out,
           c_out => sPipeLI_DI_c_out,
           op_out => sPipeLI_DI_op_out,
           CLK => CLK
           );
    
    PipeDI_EX : Pipeline
        port map (
           a_in => sPipeLI_DI_a_out,
           b_in => sMuxBdR, --returns the value directly or the value in the register
           c_in => sQB,
           op_in => sPipeLI_DI_op_out,
           a_out => sPipeDI_EX_a_out,
           b_out => sPipeDI_EX_b_out,
           c_out => sPipeDI_EX_c_out,
           op_out => sPipeDI_EX_op_out,
           CLK => CLK
           );
           
    PipeEX_Mem : Pipeline
        port map (
           a_in => sPipeDI_EX_a_out,
           b_in => sMuxAlu,
           c_in => sEmpty,
           op_in => sPipeDI_EX_op_out,
           a_out => sPipeEX_Mem_a_out,
           b_out => sPipeEX_Mem_b_out,
           c_out => sPipeEX_Mem_c_out,
           op_out => sPipeEX_Mem_op_out,
           CLK => CLK
           );
           
    PipeMem_RE : Pipeline
        port map (
           a_in => sPipeEX_Mem_a_out,
           b_in => sMuxDataMem_Output,
           c_in => sEmpty,
           op_in => sPipeEX_Mem_op_out,
           a_out => sPipeMem_RE_a_out,
           b_out => sPipeMem_RE_b_out,
           c_out => sPipeMem_RE_c_out,
           op_out => sPipeMem_RE_op_out,
           CLK => CLK
           );

    IP : Compteur_8bits
        port map (
            CLK => CLK,
            RST => RST,
            LOAD => sLOAD,
            SENS => sSENS,
            EN => sEN,
            Din => sDin,
            Dout => sCompteur
        );
    
    
    instruction_mem : Memoire_des_Instructions
        port map (
            adresse => sCompteur,
            CLK => CLK,
            output => sInstructions
        );
        
        
    banc_registres : Banc_Registre_Real
        port map (
            a_A => sPipeLI_DI_b_out(3 downto 0),
            a_B => sPipeLI_DI_c_out(3 downto 0),
            a_W => sPipeMem_RE_a_out(3 downto 0),   --the address of the register i want to write in
            W => sW,                                --depending on operation, writes or not
            DATA => sPipeMem_RE_b_out,              --the data i want to put in the register
            RST => RST,
            CLK => CLK,
            QA => sQA,
            QB => sQB
        );
        
    calculator : ALU
        port map (
            A => sPipeDI_EX_b_out,
            B => sPipeDI_EX_c_out,
            Operation => sOperation_Alu(2 downto 0),
            S => sResultat_Alu,
            C => sFlag_Unused,
            O => sFlag_Unused,
            N => sFlag_Unused
        );
        
    data_mem : Memoire_des_Donnees
        port map (
           adresse => sMuxDataMem_Input,
           INPUT  => sPipeEX_Mem_b_out,
           RW => sRW_Data_Memory,
           RST => RST,
           CLK => CLK,
           OUTPUT => sOutput_Data_Memory
        );
        
    alea_machine : Alea_Detector 
        port map (
           LI_op => sInstructions(31 downto 24),
           DI_op => sPipeLI_DI_op_out,
           EX_op => sPipeDI_EX_op_out,
           LI_b => sInstructions(15 downto 8),
           LI_c => sInstructions(7 downto 0),
           DI_a => sPipeLI_DI_a_out,
           EX_a => sPipeDI_EX_a_out,
           alea => sAlea
        );
 
  --------------------------------------------------------updating signals  --------------------------------------------------------
  
           
    --BdR MUX 
    sMuxBdR <= sPipeLI_DI_b_out when sPipeLI_DI_op_out = x"06"  or sPipeLI_DI_op_out = x"07" else --LOAD AFC
                sQA;                                                    

    --ALU LC
    sOperation_Alu <= "000" when sPipeDI_EX_op_out = x"01" else --ADD
                      "010" when sPipeDI_EX_op_out = x"02" else --MUL
                      "001" when sPipeDI_EX_op_out = x"03" else --SOU
                      "111"; -- when sPipeDI_EX_op_out = x"04";  --DIV 
                      
--                      else "011" when sPipeDI_EX_op_out = x"04" else  --AND
--                      "100" when sPipeDI_EX_op_out = x"04" else       --OR
--                      "011" when sPipeDI_EX_op_out = x"04" else       --XOR
--                      "110";                                          --NOT


    --ALU MUX
    sMuxAlu <= sResultat_Alu when sPipeDI_EX_op_out = x"01"      --ADD
                               or sPipeDI_EX_op_out = x"02"      --MUL
                               or sPipeDI_EX_op_out = x"03"      --SOU
                               or sPipeDI_EX_op_out = x"04" else --DIV 
                sPipeDI_EX_b_out;   
 
    --DATA MEM LC
    sRW_Data_Memory <= '0' when sPipeEX_Mem_op_out = x"08" else --STORE: we write 
                       '1';                                     --we read
    
     --DATA MEM INPUT MUX
    sMuxDataMem_Input <=  sPipeEX_Mem_a_out when sPipeEX_Mem_op_out = x"08" else --STORE
                          sPipeEX_Mem_b_out when sPipeEX_Mem_op_out = x"07";     --LOAD;                    
                          
    --DATA MEM OUTPUT MUX
    sMuxDataMem_Output <= sOutput_Data_Memory when sPipeEX_Mem_op_out = x"07" else --LOAD:
                          sPipeEX_Mem_b_out;
 
    --AT THE END, WRITE BACK LC
    sW <= '1' when sPipeMem_RE_op_out = x"06"      --AFC
                or sPipeMem_RE_op_out = x"05"      --COP
                or sPipeMem_RE_op_out = x"01"      --ADD
                or sPipeMem_RE_op_out = x"02"      --MUL
                or sPipeMem_RE_op_out = x"03"      --SOU    
                or sPipeMem_RE_op_out = x"04"      --DIV 
                or sPipeMem_RE_op_out = x"07" else --LOAD
          '0';                                     --STORE/NOP/JMP 
          


    --FOR ALEA: adds NOP if alea    
    sPipeLI_DI_op_in <= "00000000" when sAlea = '1' else
                         sInstructions(31 downto 24);
    
    sEN <= '1'when sAlea = '1' else
           '0';
              
    --FOR JMP
    sDin <= sInstructions(23 downto 16) when sPipeLI_DI_op_in = x"09" else --JMP
            sPipeLI_DI_a_out when (sPipeLI_DI_op_out = x"0a" and sMuxBdR /= x"01") else --JMF
             x"00";
             
    sLOAD <= '1' when sPipeLI_DI_op_in = x"09"  --JMP
                   or (sPipeLI_DI_op_out = x"0a" and sMuxBdR /= x"01") else --JMF
             '0';
    
              
    process
    begin
        wait until CLK'event and CLK = '1';
        QA <= sQA;
        QB <= sQB;   
    end process;
    
end Behavioral;