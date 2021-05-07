--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   14:00:10 05/07/2021
-- Design Name:   
-- Module Name:   /home/mauban/ProjetSysInfo/test_ALU.vhd
-- Project Name:  ProjetSysInfo
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: alu
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY test_ALU IS
END test_ALU;
 
ARCHITECTURE behavior OF test_ALU IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT alu
    PORT(
         A : IN  std_logic_vector(7 downto 0);
         B : IN  std_logic_vector(7 downto 0);
         Out_alu : OUT  std_logic_vector(7 downto 0);
         OP : IN  std_logic_vector(1 downto 0);
         N : OUT  std_logic;
         O : OUT  std_logic;
         C : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
	signal CLK : std_logic :='0';
   signal A : std_logic_vector(7 downto 0) := (others => '0');
   signal B : std_logic_vector(7 downto 0) := (others => '0');
   signal OP : std_logic_vector(1 downto 0) := (others => '0');

 	--Outputs
   signal Out_alu : std_logic_vector(7 downto 0);
   signal N : std_logic;
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
          N => N,
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
 
	 -- Stimulus process
	 
	A <= X"02";
	B <= X"01";
	OP <= "01" after 100ns, "11" after 200 ns;

END;
