--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   14:14:45 05/07/2021
-- Design Name:   
-- Module Name:   /home/mauban/ProjetSysInfo/test_datamem.vhd
-- Project Name:  ProjetSysInfo
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: data_memory
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
 
ENTITY test_datamem IS
END test_datamem;
 
ARCHITECTURE behavior OF test_datamem IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT data_memory
    PORT(
         addr : IN  std_logic_vector(7 downto 0);
         IN_mem : IN  std_logic_vector(7 downto 0);
         RW : IN  std_logic;
         RST : IN  std_logic;
         CLK : IN  std_logic;
         OUT_mem : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal addr : std_logic_vector(7 downto 0) := (others => '0');
   signal IN_mem : std_logic_vector(7 downto 0) := (others => '0');
   signal RW : std_logic := '0';
   signal RST : std_logic := '0';
   signal CLK : std_logic := '0';

 	--Outputs
   signal OUT_mem : std_logic_vector(7 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: data_memory PORT MAP (
          addr => addr,
          IN_mem => IN_mem,
          RW => RW,
          RST => RST,
          CLK => CLK,
          OUT_mem => OUT_mem
        );

   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for CLK_period/2;
		CLK <= '1';
		wait for CLK_period/2;
   end process;
 
	RST<='0', '1' after 10 ns;
   RW<= '1' after 100 ns;
	IN_mem<=X"05"; 
	addr<=x"02";

END;
