library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.all;

entity top is
	port (
		clk : in std_logic := '0';
		seg0 : out std_logic_vector(6 downto 0);-- qsys_external
		seg1 : out std_logic_vector(6 downto 0);
		seg2 : out std_logic_vector(6 downto 0);
   	reset : in  std_logic := '0'-- reset.reset_n
	);
end entity top;

architecture arch of top is

	component counter is
	port (
		clk_clk: in  std_logic := 'X'; -- clk
		reset_reset_n : in  std_logic := 'X'; -- reset_n
		pio_0_external_connection_export : out std_logic_vector(3 downto 0);
		pio_1_external_connection_export : out std_logic_vector(3 downto 0);
		pio_2_external_connection_export : out std_logic_vector(3 downto 0)
	);	end component;
	
	component bin_to_7seg is
		port (
			bin_in : in std_logic_vector (3 downto 0);
			seg_out : out std_logic_vector (6 downto 0)
		); end component;
		
		signal s0 : std_logic_vector(3 downto 0);
		signal s1 : std_logic_vector(3 downto 0);
		signal s2 : std_logic_vector(3 downto 0);
		
	begin
	u0 : component counter
		port map (
			clk_clk => clk, -- clk.clk
			reset_reset_n => reset, -- reset.reset_n
			pio_0_external_connection_export => s0, -- qsys
			pio_1_external_connection_export => s1, -- qsys
			pio_2_external_connection_export => s2 -- qsys
		);
		
	u1 : component bin_to_7seg
		port map (
			bin_in => s0,  
			seg_out => seg0
		);
	u2 : component bin_to_7seg
		port map (
		bin_in => s1,
		seg_out => seg1
		);
		
	u3 : component bin_to_7seg
		port map (
		bin_in => s2,
		seg_out => seg2
		);
		
end architecture arch;