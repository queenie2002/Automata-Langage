library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.std_logic_unsigned.ALL;
use IEEE.std_logic_arith.ALL;
use IEEE.numeric_std.all;

entity test_uP is
end test_uP;

architecture Behavioral of test_uP is

    component uP is
    Port ( CLK : in STD_LOGIC;
           RST : in STD_LOGIC;
           QA : out STD_LOGIC_VECTOR (7 downto 0);
           QB : out STD_LOGIC_VECTOR (7 downto 0));
    end component;
    
    --Inputs
    signal sRST :  STD_LOGIC := '1';
    signal sCLK :  STD_LOGIC := '0';
    
    --Outputs  
    signal QA :   STD_LOGIC_VECTOR (7 downto 0);
    signal QB :   STD_LOGIC_VECTOR (7 downto 0);


    --Clock period definitions
    constant Clock_period : time := 10 ns;


begin
  pipeline: uP port map(CLK => sCLK, RST => sRST, QA => QA, QB => QB);

    --Clock process definitions
    Clock_process : process
    begin
        sCLK <= not(sCLK);
        wait for Clock_period/2;
    end process;
    
     --Stimulus process
     sRST <= '0','1' after 10 ns; 



end Behavioral;