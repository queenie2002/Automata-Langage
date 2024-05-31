library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.std_logic_unsigned.ALL;
use IEEE.std_logic_arith.ALL;
use IEEE.numeric_std.all;

entity Alea_Detector_Test is
end Alea_Detector_Test;


architecture Behavioral of Alea_Detector_Test is

    component Alea_Detector is
    Port ( LI_op : in STD_LOGIC_VECTOR (7 downto 0);
           DI_op : in STD_LOGIC_VECTOR (7 downto 0);
           EX_op : in STD_LOGIC_VECTOR (7 downto 0);
           LI_b : in STD_LOGIC_VECTOR (7 downto 0);
           LI_c : in STD_LOGIC_VECTOR (7 downto 0);
           DI_a : in STD_LOGIC_VECTOR (7 downto 0);
           EX_a : in STD_LOGIC_VECTOR (7 downto 0);
           alea : out STD_LOGIC);
    end component;
    
    --Inputs
    signal sLI_op :   STD_LOGIC_VECTOR (7 downto 0);
    signal sDI_op :   STD_LOGIC_VECTOR (7 downto 0);
    signal sEX_op :   STD_LOGIC_VECTOR (7 downto 0);
    signal sLI_b :   STD_LOGIC_VECTOR (7 downto 0);
    signal sLI_c :   STD_LOGIC_VECTOR (7 downto 0);
    signal sDI_a :   STD_LOGIC_VECTOR (7 downto 0);
    signal sEX_a :   STD_LOGIC_VECTOR (7 downto 0);

    
    --Outputs  
    signal sAlea :   STD_LOGIC;


begin
    alea_machine : Alea_Detector 
        port map (
           LI_op => sLI_op,
           DI_op => sDI_op,
           EX_op => sEX_op,
           LI_b => sLI_b,
           LI_c => sLI_c,
           DI_a => sDI_a,
           EX_a => sEX_a,
           alea => sAlea
        );
        
       sLI_op <= x"05" ;
       sDI_op <= x"06" ;
       sEX_op <= x"00" ;
       sLI_b  <= x"01";
       sLI_c  <= x"03" ;
       sDI_a  <= x"01";
       sEX_a  <= x"00";
        
        
        


end Behavioral;