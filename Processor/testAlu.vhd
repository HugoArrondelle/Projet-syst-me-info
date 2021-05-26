LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY testAlu IS
END testAlu;
 
ARCHITECTURE behavior OF testAlu IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT alu
    PORT(
         A : IN  std_logic_vector(7 downto 0);
         B : IN  std_logic_vector(7 downto 0);
         Out_alu : OUT  std_logic_vector(7 downto 0);
         OP : IN  std_logic_vector(3 downto 0);
         O : OUT  std_logic;
         C : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
	signal CLK : std_logic :='0';
   signal A : std_logic_vector(7 downto 0) := (others => '0');
   signal B : std_logic_vector(7 downto 0) := (others => '0');
   signal OP : std_logic_vector(3 downto 0) := (others => '0');

 	--Outputs
   signal Out_alu : std_logic_vector(7 downto 0);
   signal O : std_logic;
   signal C : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
	constant CLK_period : time := 50 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: alu PORT MAP (
          A => A,
          B => B,
          Out_alu => Out_alu,
          OP => OP,
          O => O,
          C => C
        );

   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for CLK_period/2;
		CLK <= '1';
		wait for CLK_period/2;
   end process;
 
   A <= X"02";
	B <= X"01";
	OP <= "0001" after 100ns, "0011" after 200 ns;

END;
