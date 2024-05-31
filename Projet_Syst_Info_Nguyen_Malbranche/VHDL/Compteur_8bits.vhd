----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 03/08/2024 11:55:32 AM
-- Design Name: 
-- Module Name: Compteur_8bits - Behavioral
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




entity Compteur_8bits is
    Port ( CLK : in STD_LOGIC;
           RST : in STD_LOGIC;
           LOAD : in STD_LOGIC;
           SENS : in STD_LOGIC;
           EN : in STD_LOGIC;
           Din : in STD_LOGIC_VECTOR (7 downto 0);
           Dout : out STD_LOGIC_VECTOR (7 downto 0));
end Compteur_8bits;




architecture Behavioral of Compteur_8bits is
    SIGNAL compteur: STD_LOGIC_VECTOR (7 downto 0);

begin
    --process (CLK,RST,LOAD,SENS,EN)             --sensitivity list
    process
    begin
        wait until CLK'event and CLK = '1';
        if RST = '0' then
            compteur <= "00000000";
        elsif LOAD = '1' then
            compteur <= Din;
        elsif EN = '0' then
            if SENS = '0' then                 --on compte
                compteur <= compteur + 1;
            else                               --on décompte
                compteur <= compteur - 1;
            end if;
        end if;
    end process;
    
    Dout <= compteur;
    
end Behavioral;

