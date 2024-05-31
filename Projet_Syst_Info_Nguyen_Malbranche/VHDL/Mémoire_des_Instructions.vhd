----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/07/2024 09:19:02 AM
-- Design Name: 
-- Module Name: Memoire_des_Instructions - Behavioral
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


entity Memoire_des_Instructions is
    Port ( adresse : in STD_LOGIC_VECTOR (7 downto 0);
           CLK : in STD_LOGIC;
           OUTPUT : out STD_LOGIC_VECTOR (31 downto 0));
end Memoire_des_Instructions;

architecture Behavioral of Memoire_des_Instructions is
    type MemoryArray is array (0 to 255) of STD_LOGIC_VECTOR(31 downto 0); --size 256 because the addresses are on 8 bits
    signal memory : MemoryArray := (--we randomly make a table, WILL HAVE TO CHANGE, we're testing addition
    
                                    x"06001000",   --on affecte 16 au registre 0 (06 AFC 00 reg0 10 chiffre16)
                                    x"01010000",   --on additione reg0 et reg0 et met le resultat dans reg1 (01 ADD 01 reg1 00 reg0 00 reg0)
                                    others => (others => '0')
                                    );  
    
begin


    process
    begin
        wait until CLK'event and CLK = '1';
        OUTPUT <= memory(conv_integer(adresse));
    end process;


end Behavioral;
