----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 03/14/2024 08:30:48 AM
-- Design Name: 
-- Module Name: Compteur_8bits_Test - Behavioral
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
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_unsigned.ALL;
use IEEE.std_logic_arith.ALL;
use IEEE.numeric_std.all;



entity Compteur_8bits_Test is
--  Port ( );
end Compteur_8bits_Test;

architecture Behavioral of Compteur_8bits_Test is
    
    component Compteur_8bits is
        Port ( CLK : in STD_LOGIC;
               RST : in STD_LOGIC;
               LOAD : in STD_LOGIC;
               SENS : in STD_LOGIC;
               EN : in STD_LOGIC;
               Din : in STD_LOGIC_VECTOR (7 downto 0);
               Dout : out STD_LOGIC_VECTOR (7 downto 0));
    end component;
    
    signal sCLK : std_logic;
    signal sSENS : std_logic;
    signal sRST : std_logic;
    signal sLOAD : std_logic;
    signal sEN : std_logic;
    signal sDin : std_logic_vector (7 downto 0);
    signal sDout : std_logic_vector (7 downto 0);

begin

 compteur: Compteur_8bits port map(sCLK,sRST,sLOAD,sSENS,sEN,sDin,sDout);


clock: process
begin
    wait for 10 ns;
    sCLK <= '0';
    wait for 10 ns;
    sCLK <= '1';
end process;

--sRST <=  '0', '1' after 20ns;
--sLOAD <= '0', '1' after 10ns,'1' after 50ns;
--sSENS <= '0', '1' after 70ns,'1' after 120ns,'0' after 180ns;
--sEN <=   '0', '1' after 200ns;
--sDin <= "11110000";
       --rst, rst          , load
sRST <=  '0',               '1' after 20ns;
sSENS <= '1';
sEN <=   '1';
sLOAD <= '0','1' after 10ns                , '1' after 10ns;
sDin <= "00001111";




end Behavioral;
