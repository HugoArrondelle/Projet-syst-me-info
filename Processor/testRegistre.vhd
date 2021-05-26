LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY testRegistre IS
END testRegistre;
 
ARCHITECTURE behavior OF testRegistre IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT registre
    PORT(
         addrA : IN  std_logic_vector(3 downto 0);
         addrB : IN  std_logic_vector(3 downto 0);
         addrW : IN  std_logic_vector(3 downto 0);
         W : IN  std_logic;
         DATA : IN  std_logic_vector(7 downto 0);
         RST : IN  std_logic;
         CLK : IN  std_logic;
         QA : OUT  std_logic_vector(7 downto 0);
         QB : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal addrA : std_logic_vector(3 downto 0) := (others => '0');
   signal addrB : std_logic_vector(3 downto 0) := (others => '0');
   signal addrW : std_logic_vector(3 downto 0) := (others => '0');
   signal W : std_logic := '0';
   signal DATA : std_logic_vector(7 downto 0) := (others => '0');
   signal RST : std_logic := '0';
   signal CLK : std_logic := '0';

 	--Outputs
   signal QA : std_logic_vector(7 downto 0);
   signal QB : std_logic_vector(7 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 50 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: registre PORT MAP (
          addrA => addrA,
          addrB => addrB,
          addrW => addrW,
          W => W,
          DATA => DATA,
          RST => RST,
          CLK => CLK,
          QA => QA,
          QB => QB
        );

   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for CLK_period/2;
		CLK <= '1';
		wait for CLK_period/2;
   end process;
 

   RST <= '0';
	W <= '1' after 50 ns;
	DATA <= X"02";
	addrW <= X"0" after 60 ns;
	addrA <= X"1" after 60 ns;
	addrB <= X"2" after 60 ns;

END;
