--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   17:55:29 05/04/2021
-- Design Name:   
-- Module Name:   /home/mauban/ProjetSysInfo/processor_test.vhd
-- Project Name:  ProjetSysInfo
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: processor
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
 
ENTITY processor_test IS
END processor_test;
 
ARCHITECTURE behavior OF processor_test IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT processor
    PORT(
         CLK_PROC : IN  std_logic;
         RST_PROC : IN  std_logic;
         IP : IN  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal CLK_PROC : std_logic := '0';
   signal RST_PROC : std_logic := '0';
   signal IP : std_logic_vector(7 downto 0) := (others => '0');

   -- Clock period definitions
   constant CLK_PROC_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: processor PORT MAP (
          CLK_PROC => CLK_PROC,
          RST_PROC => RST_PROC,
          IP => IP
        );

   -- Clock process definitions
   CLK_PROC_process :process
   begin
		CLK_PROC <= '0';
		wait for CLK_PROC_period/2;
		CLK_PROC <= '1';
		wait for CLK_PROC_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for CLK_PROC_period*10;

      -- insert stimulus here 

      wait;
   end process;

END;
