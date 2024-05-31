----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/07/2024 08:48:46 AM
-- Design Name: 
-- Module Name: Memoire_des_Donnees_Test - Behavioral
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


entity Memoire_des_Donnees_Test is
end Memoire_des_Donnees_Test;

architecture Behavioral of Memoire_des_Donnees_Test is

    component Memoire_des_Donnees is
    Port ( adresse : in STD_LOGIC_VECTOR (7 downto 0);
           INPUT : in STD_LOGIC_VECTOR (7 downto 0);
           RW : in STD_LOGIC;
           RST : in STD_LOGIC;
           CLK : in STD_LOGIC;
           OUTPUT : out STD_LOGIC_VECTOR (7 downto 0));
    end component;
    
    
    --Inputs
    signal sadresse :  STD_LOGIC_VECTOR (7 downto 0);
    signal sinput :  STD_LOGIC_VECTOR (7 downto 0);
    signal sRW :    STD_LOGIC;
    signal sRST :    STD_LOGIC;
    signal sCLK :    STD_LOGIC := '0';
    
    --Outputs  
    signal sOUTPUT : STD_LOGIC_VECTOR (7 downto 0);


    -- Clock period definitions
    constant Clock_period : time := 10 ns;    
    
begin
    mem: Memoire_des_Donnees port map(sadresse, sinput, sRW, sRST, sCLK, sOUTPUT);

    -- Clock process definitions
    Clock_process : process
    begin
        sCLK <= not(sCLK);
        wait for Clock_period/2;
    end process;

    -- Stimulus process
    sadresse <=   "00000001",                        "00000010" after 20 ns,                   "00000001" after 50 ns,  "00000101" after 60 ns, "00000001" after 70 ns ;
    sRW <=        '1',                               '0' after 20 ns,        '1' after 30 ns,  '0' after 50 ns,        '1' after 60 ns;
    sinput <=     "11111111",                                                                  "00100010" after 50 ns;
    sRST <=       '1',        '0' after 10 ns,       '1' after 20 ns; 
    --shouldn't have anything, resets to 0 reads 0,  écrit dans 00000010,     je lis 11111111,  on écrit dans 00000001, on devrait rien lire ici, on devrait lire 00100010 ici 

end Behavioral;
