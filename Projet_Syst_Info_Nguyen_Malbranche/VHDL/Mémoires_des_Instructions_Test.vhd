----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/07/2024 02:18:31 PM
-- Design Name: 
-- Module Name: Memoires_des_Instructions_Test - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.std_logic_unsigned.ALL;
use IEEE.std_logic_arith.ALL;
use IEEE.numeric_std.all;

entity Memoires_des_Instructions_Test is
end Memoires_des_Instructions_Test;

architecture Behavioral of Memoires_des_Instructions_Test is

    component Memoire_des_Instructions is
    Port ( adresse : in STD_LOGIC_VECTOR (7 downto 0);
           CLK : in STD_LOGIC;
           OUTPUT : out STD_LOGIC_VECTOR (31 downto 0));
    end component;
    
    --Inputs
    signal sadresse :  STD_LOGIC_VECTOR (7 downto 0);
    signal sCLK :  STD_LOGIC := '0';
    
    --Outputs  
    signal sOUTPUT : STD_LOGIC_VECTOR (31 downto 0);

    --Clock period definitions
    constant Clock_period : time := 10 ns;
    
begin
    data_mem: Memoire_des_Instructions port map(sadresse, sCLK, sOUTPUT);

    --Clock process definitions
    Clock_process : process
    begin
        sCLK <= not(sCLK);
        wait for Clock_period/2;
    end process;
    
     --Stimulus process
    sadresse <= "00000100" after 10 ns, "00000000" after 20 ns, "00000001" after 30 ns, "00010001" after 40 ns,  "00000001" after 50 ns; 
    

end Behavioral;
