library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.std_logic_unsigned.ALL;
use IEEE.std_logic_arith.ALL;
use IEEE.numeric_std.all;


entity Pipeline is
    Port ( a_in : in STD_LOGIC_VECTOR (7 downto 0);
           b_in : in STD_LOGIC_VECTOR (7 downto 0);
           c_in : in STD_LOGIC_VECTOR (7 downto 0);
           op_in : in STD_LOGIC_VECTOR (7 downto 0);
           a_out : out STD_LOGIC_VECTOR (7 downto 0);
           b_out : out STD_LOGIC_VECTOR (7 downto 0);
           c_out : out STD_LOGIC_VECTOR (7 downto 0);
           op_out : out STD_LOGIC_VECTOR (7 downto 0);
           CLK : in STD_LOGIC);
end Pipeline;

architecture Behavioral of Pipeline is

begin
    process
    begin
        wait until CLK'event and CLK = '1';
        a_out <= a_in;
        b_out <= b_in;
        c_out <= c_in;
        op_out<= op_in;
    end process;
    
end Behavioral;
