library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;


entity processor is
	port( CLK_PROC : in STD_LOGIC;
			RST_PROC : in STD_LOGIC;
			IP: in STD_LOGIC_VECTOR(7 downto 0));
end processor;

architecture Behavioral of processor is
	
     -- Composants du processeur
    
    ------------------------------------------------------
    -- ALU --
    ------------------------------------------------------
    
    component alu is
        Port (  A       : in STD_LOGIC_VECTOR (7 downto 0);
                B       : in STD_LOGIC_VECTOR (7 downto 0);
                Out_alu : out STD_LOGIC_VECTOR (7 downto 0);
                OP      : in STD_LOGIC_VECTOR (3 downto 0);
                O       : out STD_LOGIC;
                C       : out STD_LOGIC
         );
    end component;
    
    ------------------------------------------------------
    -- PIPELINE --
    ------------------------------------------------------
    
    component pipeline is
        Port (  CLK     : in  STD_LOGIC;
                A_in    : in  STD_LOGIC_VECTOR (7 downto 0);
                OP_in   : in  STD_LOGIC_VECTOR (7 downto 0);
                B_in    : in  STD_LOGIC_VECTOR (7 downto 0);
                C_in    : in  STD_LOGIC_VECTOR (7 downto 0);
                A_out   : out  STD_LOGIC_VECTOR (7 downto 0);
                OP_out  : out  STD_LOGIC_VECTOR (7 downto 0);
                B_out   : out  STD_LOGIC_VECTOR (7 downto 0);
                C_out   : out  STD_LOGIC_VECTOR (7 downto 0)
				 );
    end component;
    

    ------------------------------------------------------
    -- REGISTRE --
    ------------------------------------------------------
    
    component registre is
        Port (  addrA   : in  STD_LOGIC_VECTOR (3 downto 0);
                addrB   : in  STD_LOGIC_VECTOR (3 downto 0);
                addrW   : in  STD_LOGIC_VECTOR (3 downto 0);
                W       : in  STD_LOGIC;
                DATA    : in  STD_LOGIC_VECTOR (7 downto 0);
                RST     : in  STD_LOGIC;
                CLK     : in  STD_LOGIC;
                QA      : out  STD_LOGIC_VECTOR (7 downto 0);
                QB      : out  STD_LOGIC_VECTOR (7 downto 0));
    end component;
    
    ------------------------------------------------------
    -- DATA MEMORY --
    ------------------------------------------------------
    
    
    component data_memory is
       Port (   addr    : in  STD_LOGIC_VECTOR (7 downto 0);
                IN_mem  : in  STD_LOGIC_VECTOR (7 downto 0);
                RW      : in  STD_LOGIC;
                RST     : in  STD_LOGIC;
                CLK     : in  STD_LOGIC;
                OUT_mem : out  STD_LOGIC_VECTOR (7 downto 0));
    end component;
    
    ------------------------------------------------------
    -- INSTRUCTION MEMORY --
    ------------------------------------------------------
    
    
    component instr_memory is
    
        Port (  addr    		  : in  STD_LOGIC_VECTOR (7 downto 0);
                CLK    			  : in  STD_LOGIC;
                OUT_instruction : out  STD_LOGIC_VECTOR (31 downto 0));
    end component;
    
    ------------------------------------------------------
    -- MUX 0 --
    ------------------------------------------------------
    
    component mux is
    
        Generic ( mux_number : NATURAL := 0);
        Port (  A       : in  STD_LOGIC_VECTOR (7 downto 0);
                B       : in  STD_LOGIC_VECTOR (7 downto 0);
                OP      : in  STD_LOGIC_VECTOR (7 downto 0);
                OUT_mux : out STD_LOGIC_VECTOR (7 downto 0));
    end component;
    
    ------------------------------------------------------
    -- LC --
    ------------------------------------------------------
    
    component lc is
    
        Generic ( lc_number : STD_LOGIC := '0');
        Port (  OP      : in  STD_LOGIC_VECTOR (7 downto 0);
                val     : out  STD_LOGIC);
                
    end component;
    
    
    signal IP_AUX :                                                 STD_LOGIC_VECTOR(7 downto 0);
    signal OP_DI,OP_EX, OP_MEM, OP_RE:                              STD_LOGIC_VECTOR(7 downto 0);
    signal A_DI, B_DI, C_DI :                                       STD_LOGIC_VECTOR(7 downto 0);
    signal A_EX, B_EX, C_EX :                                       STD_LOGIC_VECTOR(7 downto 0);
    signal A_MEM, B_MEM, C_MEM :                                    STD_LOGIC_VECTOR(7 downto 0);
    signal A_RE, B_RE, C_RE :                                       STD_LOGIC_VECTOR(7 downto 0);
    
    signal Reg_QA, Reg_QB :                                         STD_LOGIC_VECTOR(7 downto 0);
    signal UAL_OUT,DATA_MEM_OUT :                                   STD_LOGIC_VECTOR(7 downto 0);
    signal Instruction:                                             STD_LOGIC_VECTOR(31 downto 0);
        
    signal UAL_C_Flag, UAL_O_Flag :          							  STD_LOGIC;
    signal Mux_BdR_Out, Mux_UAL_Out ,Mux_MEM1_Out,Mux_MEM2_Out:     STD_LOGIC_VECTOR(7 downto 0);
    
    signal LC_out,LC_UAL_out,LC_MEM_out :                           STD_LOGIC;
    signal Ctrl_alu_Aux :                                           STD_LOGIC_VECTOR(3 downto 0);
    
    
  begin  
	 ------------------------------------------------------
    -- Instr_Mem --
    ------------------------------------------------------
    Instr_Mem : instr_memory PORT MAP   (
                                            addr =>         		IP,
														  CLK =>          		CLK_PROC,
                                            OUT_instruction =>    Instruction
                                        );
        

    ------------------------------------------------------
    -- LI_DI --
    ------------------------------------------------------
    
    Li_Di: pipeline PORT MAP (
                                    CLK =>      CLK_PROC,
                                    A_in =>     Instruction(23 downto 16),
                                    OP_in =>    Instruction(31 downto 24),
                                    B_in =>     Instruction(15 downto 8),
                                    C_in =>     Instruction(7 downto 0),
                                    
                                    A_out =>    A_DI,
                                    OP_out =>   OP_DI,
                                    B_out =>    B_DI,
                                    C_out =>    C_DI
                                
                                );
                                
    ------------------------------------------------------
    -- Di_Ex --
    ------------------------------------------------------
    
    Di_EX: pipeline PORT MAP (
                                    CLK =>      CLK_PROC,
                                    A_in =>     A_DI,
                                    OP_in =>    OP_DI,
                                    B_in =>     Mux_BdR_Out,
                                    C_in =>     Reg_QB,
                                    
                                    A_out =>    A_EX,
                                    OP_out =>   OP_EX,
                                    B_out =>    B_EX,
                                    C_out =>    C_EX
                                
                            );
    ------------------------------------------------------
    -- EX_MEM --
    ------------------------------------------------------
    EX_MEM: pipeline PORT MAP   (
                                    CLK =>      CLK_PROC,
                                    A_in =>     A_EX,
                                    OP_in =>    OP_EX,
                                    B_in =>     Mux_UAL_Out,
                                    C_in =>     C_EX,
                                    A_out =>    A_MEM,
                                    OP_out =>   OP_MEM,
                                    B_out =>    B_MEM,
                                    C_out =>    C_MEM
                                );
    
    ------------------------------------------------------
    -- MEM_RE --
    ------------------------------------------------------
    MEM_RE: pipeline PORT MAP   (
                                    CLK =>      CLK_PROC,
                                    A_in =>     A_MEM,
                                    OP_in =>    OP_MEM,
                                    B_in =>     Mux_MEM1_Out,
                                    C_in =>     C_MEM,
                                    A_out =>    A_RE,
                                    OP_out =>   OP_RE,
                                    B_out =>    B_RE,
                                    C_out =>    C_RE
                                );
                                
    ------------------------------------------------------
    -- LC 0 --
    ------------------------------------------------------
    LOG_C : lc Generic map ('0')  PORT MAP (
                                    OP=>        OP_RE,
                                    val =>      LC_out
    );
    
    ------------------------------------------------------
    -- REGISTRE --
    ------------------------------------------------------
    Reg : registre PORT MAP(
                                    addrA=>     B_DI(3 downto 0),
                                    addrB=>     C_DI(3 downto 0),
                                    addrW =>    A_RE(3 downto 0),
                                    W=>         LC_out,
                                    DATA=>      B_RE,
                                    RST=>       RST_PROC,
                                    CLK=>       CLK_PROC,
                                    QA=>        Reg_QA,
                                    QB=>        Reg_QB
    );
    

    ------------------------------------------------------
    -- MUX 1 --
    ------------------------------------------------------
    
    Multiplexeur_BdR : MUX
    Generic map (1)
    PORT MAP (
                                    A=>         B_DI,
                                    B=>         Reg_QA,
                                    OP=>        OP_DI,
                                    OUT_mux=>   Mux_BdR_Out
             );
             
    ------------------------------------------------------
    -- MUX 2 --
    ------------------------------------------------------
    
    Multiplexeur_UAL : MUX
    Generic map (2)
    PORT MAP(
                                    A=>         B_EX,
                                    B=>         UAL_OUT,
                                    OP=>        OP_EX,
                                    OUT_mux=>   Mux_UAL_Out
    );
    
    ------------------------------------------------------
    -- UAL --
    ------------------------------------------------------
    
    UAL : ALU PORT MAP(
                                    A =>        B_EX,
                                    B =>        C_EX,
                                    Out_alu =>  UAL_OUT,
                                    OP =>       Ctrl_alu_Aux,
                                    C =>   		UAL_C_Flag,
                                    O =>   		UAL_O_Flag
    );
    
    
    Ctrl_alu_Aux <= B"0" & OP_EX(2 downto 0);
        
    ------------------------------------------------------
    -- Data_MEM --
    ------------------------------------------------------
    
    Data_MEM : data_memory Port MAP(
                                    addr =>     Mux_MEM2_Out,
                                    IN_mem  =>  B_MEM,
                                    RW =>       LC_MEM_out,
                                    RST =>      RST_PROC,
                                    CLK =>      CLK_PROC,
                                    OUT_mem =>  DATA_MEM_OUT
    );
     
    ------------------------------------------------------
    -- MUX 3 --
    ------------------------------------------------------
    
    Multiplexeur_MEM1 : MUX
    Generic map (3)
    PORT MAP(
                                    A=>         DATA_MEM_OUT,
                                    B=>         B_MEM,
                                    OP=>        OP_MEM,
                                    OUT_mux=>   Mux_MEM1_Out
    );
    
    ------------------------------------------------------
    -- LC 1 --
    ------------------------------------------------------
    LC_MEM : lc Generic map ('1')
    PORT MAP (
                                    OP=>        OP_MEM,
                                    val =>      LC_MEM_out
    );
    
    ------------------------------------------------------
    -- MUX 4 --
    ------------------------------------------------------
    
    Multiplexeur_MEM2 : MUX
    Generic map (4)
    PORT MAP(
                                    A=>         A_MEM,
                                    B=>         B_MEM,
                                    OP=>        OP_MEM,
                                    OUT_mux=>   Mux_MEM2_Out
    );
    
    
        
    
end Behavioral;
