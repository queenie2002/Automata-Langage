----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 03/21/2024 12:31:29 PM
-- Design Name: 
-- Module Name: Banc_Registre_Real - Behavioral
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


entity Banc_Registre_Real is
    Port ( a_A : in STD_LOGIC_VECTOR (3 downto 0);
           a_B : in STD_LOGIC_VECTOR (3 downto 0);
           a_W : in STD_LOGIC_VECTOR (3 downto 0);
           W : in STD_LOGIC;
           DATA : in STD_LOGIC_VECTOR (7 downto 0);
           RST : in STD_LOGIC;
           CLK : in STD_LOGIC;
           QA : out STD_LOGIC_VECTOR (7 downto 0);
           QB : out STD_LOGIC_VECTOR (7 downto 0));
end Banc_Registre_Real;



-- we are always reading and sending 
architecture Behavioral of Banc_Registre_Real is
    type RegisterArray is array (0 to 15) of STD_LOGIC_VECTOR(7 downto 0); --16 registers because the address are on 4 bits, so the number of registers we can see are 16
    signal registers : RegisterArray;      
    

begin
    process
    begin
        wait until CLK'event and CLK = '1';
                
        --we reset
        if RST = '0' then
            registers <= (others => "00000000");   
            
        --we write
        elsif W = '1' then
            registers(conv_integer(a_W)) <= DATA; --writes Data in registers at @W
        end if;
        
          
    end process;
    
    
    QA <= DATA when W = '1' and (a_A=a_W)
        else registers(conv_integer(a_A));
    QB <= DATA when W = '1' and (a_B=a_W)
        else registers(conv_integer(a_B));
    
    
end Behavioral;




