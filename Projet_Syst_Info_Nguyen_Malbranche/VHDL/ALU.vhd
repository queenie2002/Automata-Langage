----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 03/03/2024 05:44:55 PM
-- Design Name: 
-- Module Name: ALU - Behavioral
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

--HAD TO ADD THOSE
use IEEE.std_logic_1164.ALL;
use IEEE.std_logic_unsigned.ALL;
use IEEE.std_logic_arith.ALL;



-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ALU is
    Port ( A : in STD_LOGIC_VECTOR (7 downto 0);
           B : in STD_LOGIC_VECTOR (7 downto 0);
           Operation : in STD_LOGIC_VECTOR (2 downto 0);
           S : out STD_LOGIC_VECTOR (7 downto 0);
           C : out STD_LOGIC;
           O : out STD_LOGIC;
           N : out STD_LOGIC);
end ALU;





architecture Behavioral of ALU is  
    
    --ON FAIT DES SIGNAUX TEMPORAIRES QU'ON ASSIGN APRES, ON MET PAS DE IN OUT 
    SIGNAL tmp: STD_LOGIC_VECTOR (7 downto 0);          --pour tout en général
    SIGNAL tmp1: STD_LOGIC_VECTOR (8 downto 0);         --pour additionner CARRY
    SIGNAL tmp2: STD_LOGIC_VECTOR (15 downto 0);        --pour multiplier OVERFLOW

    
begin
    process (A,B,Operation)             --sensitivity list
    begin
        case Operation is
        when "000" => --ADD
            tmp1 <= ('0'&A) + ('0'&B)  ;    --had to concaténer un 0 pour que ça fasse la bonne taille + parenthèses
        when "001" => --SUBS
            tmp <= A - B  ;     
        when "010" => --MUL
            tmp2 <= A * B  ;     --8bits*8bits = 16
        when "011" => --AND
            tmp <= A and B  ;    
        when "100" => --OR
            tmp <= A or B  ;
        when "101" => --XOR
            tmp <= A xor B  ;
        when "110" =>  --NOT
            tmp <= not A ;    
        when others => 
            tmp <= not X"FF";
        end case;
        
    
    end process;


    --ON DOIT LE FAIRE APRES PROCESS SINON CE SERA PAS LES VALEURS LES PLUS RECENTES
    S <= tmp2(7 downto 0) when operation = "010" else    --faut couper pour que ça fasse taille 8bits
         tmp1(7 downto 0) when operation = "000" else
         tmp;
         
    C <= '1' when (operation = "000" and tmp1 > X"FF") else  --si c'est plus grand que 11111111 c'est que we carry over
         '0';
    O <= '1' when (operation = "010" and tmp2 > X"FF") else  --si c'est plus grand que 11111111 c'est que we overflow over
         '0';
    N <= '1' when (operation = "001" and A<B) else
         '0';
     
    
end Behavioral;













