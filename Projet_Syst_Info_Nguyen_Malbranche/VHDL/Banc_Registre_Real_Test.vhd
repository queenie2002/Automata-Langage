----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/03/2024 02:32:32 PM
-- Design Name: 
-- Module Name: Banc_Registre_Real_Test - Behavioral
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


entity Banc_Registre_Real_Test is
end Banc_Registre_Real_Test;

architecture Behavioral of Banc_Registre_Real_Test is

    component Banc_Registre_Real is
    Port ( a_A : in STD_LOGIC_VECTOR (3 downto 0);
           a_B : in STD_LOGIC_VECTOR (3 downto 0);
           a_W : in STD_LOGIC_VECTOR (3 downto 0);
           W : in STD_LOGIC;
           DATA : in STD_LOGIC_VECTOR (7 downto 0);
           RST : in STD_LOGIC;
           CLK : in STD_LOGIC;
           QA : out STD_LOGIC_VECTOR (7 downto 0);
           QB : out STD_LOGIC_VECTOR (7 downto 0));
    end component;



    --Inputs
    signal sa_A :  STD_LOGIC_VECTOR (3 downto 0) := (others => '0');
    signal sa_B :  STD_LOGIC_VECTOR (3 downto 0):= (others => '0');
    signal sa_W :  STD_LOGIC_VECTOR (3 downto 0):= (others => '0');
    signal sW :    STD_LOGIC := '0';
    signal sDATA : STD_LOGIC_VECTOR (7 downto 0) := (others => '0');
    signal sRST :  STD_LOGIC := '0';
    signal sCLK :  STD_LOGIC := '0';
    
    --Outputs  
    signal sQA :   STD_LOGIC_VECTOR (7 downto 0);
    signal sQB :   STD_LOGIC_VECTOR (7 downto 0);


    --Clock period definitions
    constant Clock_period : time := 10 ns;


begin

    banc_registre: Banc_Registre_Real port map(sa_A, sa_B, sa_W, sW, sDATA, sRST, sCLK, sQA, sQB);


    --Clock process definitions
    Clock_process : process
    begin
        sCLK <= not(sCLK);
        wait for Clock_period/2;
    end process;
    
    
    
    --Stimulus process
    sa_A <= "0001" after 10 ns, "0010" after 20 ns, "0001" after 30 ns, "0001" after 40 ns,  "0001" after 50 ns;
    sa_B <= "0101" after 10 ns, "0010" after 20 ns, "0010" after 30 ns, "0001" after 40 ns,  "1010" after 50 ns,  "1011" after 80 ns;
    sa_W <=                                         "0001" after 30 ns,                     "1011" after 50 ns;
    sW <=                                           '1' after 30 ns,                       '0' after 50 ns,      '1' after 70ns;
    sDATA <=                                         "11111111" after 30 ns,                "00100010" after 50 ns;
    sRST <= '1' after 10 ns,                                                                                            '0' after 70 ns; 
    --should have 0 at first,                        écrit  0001, on le lit 2 fois      on écrit dans 1010 
end Behavioral;
