library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.std_logic_unsigned.ALL;
use IEEE.std_logic_arith.ALL;
use IEEE.numeric_std.all;

entity Pipeline_Test is
end Pipeline_Test;

architecture Behavioral of Pipeline_Test is
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

     --Inputs
    signal sCLK :  STD_LOGIC := '0';
    signal sa_in :   STD_LOGIC_VECTOR (7 downto 0);
    signal sb_in :   STD_LOGIC_VECTOR (7 downto 0);
    signal sc_in :   STD_LOGIC_VECTOR (7 downto 0);
    signal sop_in :   STD_LOGIC_VECTOR (7 downto 0);
    
    --Outputs  
    signal sa_out :   STD_LOGIC_VECTOR (7 downto 0);
    signal sb_out :   STD_LOGIC_VECTOR (7 downto 0);
    signal sc_out :   STD_LOGIC_VECTOR (7 downto 0);
    signal sop_out :   STD_LOGIC_VECTOR (7 downto 0);



    --Clock period definitions
    constant Clock_period : time := 10 ns;


begin
      pipe: Pipeline port map(sa_in, sb_in, sc_in, sop_in, sa_out, sb_out, sc_out, sop_out, sCLK);

    --Clock process definitions
    Clock_process : process
    begin
        sCLK <= not(sCLK);
        wait for Clock_period/2;
    end process;
    
     --Stimulus process
     sa_in <= "00000001" after 10 ns, "00000010" after 20 ns; 
     sb_in <= "00000011" after 10 ns, "00000100" after 20 ns; 
     sc_in <= "00000101" after 10 ns, "00000110" after 20 ns; 
     sop_in <= "00000111" after 10 ns, "00001000" after 20 ns; 

end Behavioral;
