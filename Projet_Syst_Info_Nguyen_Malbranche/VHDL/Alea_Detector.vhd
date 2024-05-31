library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.std_logic_unsigned.ALL;
use IEEE.std_logic_arith.ALL;
use IEEE.numeric_std.all;

entity Alea_Detector is
    Port ( LI_op : in STD_LOGIC_VECTOR (7 downto 0);
           DI_op : in STD_LOGIC_VECTOR (7 downto 0);
           EX_op : in STD_LOGIC_VECTOR (7 downto 0);
           LI_b : in STD_LOGIC_VECTOR (7 downto 0);
           LI_c : in STD_LOGIC_VECTOR (7 downto 0);
           DI_a : in STD_LOGIC_VECTOR (7 downto 0);
           EX_a : in STD_LOGIC_VECTOR (7 downto 0);
           alea : out STD_LOGIC);
end Alea_Detector;

architecture Behavioral of Alea_Detector is
    signal sReadAlea : std_logic;
    signal sWriteAleaDI : std_logic;
    signal sWriteAleaEX : std_logic;

begin
        sWriteAleaDI <= '1' when DI_op = x"06"      --AFC
                          or DI_op = x"01"      --ADD
                          or DI_op = x"02"      --MUL
                          or DI_op = x"03"      --SOU
                          or DI_op = x"04"      --DIV
                          or DI_op = x"05"      --COP
                          or DI_op = x"07" else --LOAD                          
                  '0';              
                  
                  
    sWriteAleaEX <= '1' when EX_op = x"06"      --AFC
                          or EX_op = x"01"      --ADD
                          or EX_op = x"02"      --MUL
                          or EX_op = x"03"      --SOU
                          or EX_op = x"04"      --DIV
                          or EX_op = x"05"      --COP
                          or EX_op = x"07" else --LOAD                          
                  '0';                                           

    sReadAlea <= '1' when LI_op  = x"01"       --ADD
                       or LI_op  = x"02"       --MUL
                       or LI_op  = x"03"       --SOU
                       or LI_op  = x"04"       --DIV NON IMPLEMENTE DANS ALU
                       or LI_op  = x"05"       --COP    
                       or LI_op  = x"08" else  --STORE
                 '0';          
    
    alea <= '1' when (sReadAlea='1' and                                            --if i'm reading
                                         ((sWriteAleaDI='1' and (LI_b = DI_a        --and i'm writing in DI and the register i'm reading into
                                                              or LI_c=DI_a))        --is the one i'm writing into for B or C then ALEA

                                       or (sWriteAleaEX='1' and (LI_b=EX_a          --and i'm writing in EX and the register i'm reading into
                                                              or LI_c=EX_a)))) else --is the one i'm writing into for B or C then ALEA
             '0' ;
             

end Behavioral;
