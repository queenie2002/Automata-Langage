----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/07/2024 08:34:17 AM
-- Design Name: 
-- Module Name: Memoire_des_Donnees - Behavioral
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


entity Memoire_des_Donnees is
    Port ( adresse : in STD_LOGIC_VECTOR (7 downto 0);
           INPUT : in STD_LOGIC_VECTOR (7 downto 0);
           RW : in STD_LOGIC;
           RST : in STD_LOGIC;
           CLK : in STD_LOGIC;
           OUTPUT : out STD_LOGIC_VECTOR (7 downto 0));
end Memoire_des_Donnees;

architecture Behavioral of Memoire_des_Donnees is
    type MemoryArray is array (0 to 255) of STD_LOGIC_VECTOR(7 downto 0); --size 256 because the addresses are on 8 bits
    signal memory : MemoryArray;  
    

begin
    process
    begin
        wait until CLK'event and CLK = '1';
                
        --we reset
        if RST = '0' then
            memory <= (others => "00000000");   
        end if;
            
        --we write
        if RW = '0' then
            memory(conv_integer(adresse)) <= INPUT; --writes input in memory at @
        end if;
        
    end process;
   
    --we read
    OUTPUT <= memory(conv_integer(adresse)) when RW='1';

    
    
end Behavioral;

