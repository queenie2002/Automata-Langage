library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.std_logic_unsigned.ALL;
use IEEE.std_logic_arith.ALL;
use IEEE.numeric_std.all;

entity ALU_Test is
end ALU_Test;

architecture Behavioral of ALU_Test is

    component ALU is
        Port ( A : in STD_LOGIC_VECTOR (7 downto 0);
               B : in STD_LOGIC_VECTOR (7 downto 0);
               Operation : in STD_LOGIC_VECTOR (2 downto 0);
               S : out STD_LOGIC_VECTOR (7 downto 0);
               C : out STD_LOGIC;
               O : out STD_LOGIC;
               N : out STD_LOGIC);
    end component;
    
    --Inputs
    signal sA :  STD_LOGIC_VECTOR (7 downto 0);
    signal sB :  STD_LOGIC_VECTOR (7 downto 0);
    signal sOperation :  STD_LOGIC_VECTOR (2 downto 0);

    --Outputs  
    signal sS : STD_LOGIC_VECTOR (7 downto 0);
    signal sC : STD_LOGIC;
    signal sO : STD_LOGIC;
    signal sN : STD_LOGIC;

begin
  alu_test: ALU port map(sA, sB, sOperation, sS, sC, sO, sN);
  
     --Stimulus process
     sA <= x"0c",x"0F" after 20 ns; 
     sB <=x"04",x"03" after 10 ns; 
     sOperation <= "111"; 



end Behavioral;

