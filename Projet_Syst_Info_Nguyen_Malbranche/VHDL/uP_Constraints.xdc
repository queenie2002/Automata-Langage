create_clock -period 10.000 -name CLK -waveform {0.000 5.000} [get_ports CLK]

#CLK
set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets CLK]
set_property -dict {PACKAGE_PIN U18 IOSTANDARD LVCMOS33} [get_ports CLK]

#RST
set_property -dict {PACKAGE_PIN W19 IOSTANDARD LVCMOS33} [get_ports RST]

#Output QA
set_property -dict {PACKAGE_PIN V13 IOSTANDARD LVCMOS33} [get_ports {QA[0]}]
set_property -dict {PACKAGE_PIN V3 IOSTANDARD LVCMOS33} [get_ports {QA[1]}]
set_property -dict {PACKAGE_PIN W3 IOSTANDARD LVCMOS33} [get_ports {QA[2]}]
set_property -dict {PACKAGE_PIN U3 IOSTANDARD LVCMOS33} [get_ports {QA[3]}]
set_property -dict {PACKAGE_PIN P3 IOSTANDARD LVCMOS33} [get_ports {QA[4]}]
set_property -dict {PACKAGE_PIN N3 IOSTANDARD LVCMOS33} [get_ports {QA[5]}]
set_property -dict {PACKAGE_PIN P1 IOSTANDARD LVCMOS33} [get_ports {QA[6]}]
set_property -dict {PACKAGE_PIN L1 IOSTANDARD LVCMOS33} [get_ports {QA[7]}]

#Output QB
set_property -dict {PACKAGE_PIN U16 IOSTANDARD LVCMOS33} [get_ports {QB[0]}]
set_property -dict {PACKAGE_PIN E19 IOSTANDARD LVCMOS33} [get_ports {QB[1]}]
set_property -dict {PACKAGE_PIN U19 IOSTANDARD LVCMOS33} [get_ports {QB[2]}]
set_property -dict {PACKAGE_PIN V19 IOSTANDARD LVCMOS33} [get_ports {QB[3]}]
set_property -dict {PACKAGE_PIN W18 IOSTANDARD LVCMOS33} [get_ports {QB[4]}]
set_property -dict {PACKAGE_PIN U15 IOSTANDARD LVCMOS33} [get_ports {QB[5]}]
set_property -dict {PACKAGE_PIN U14 IOSTANDARD LVCMOS33} [get_ports {QB[6]}]
set_property -dict {PACKAGE_PIN V14 IOSTANDARD LVCMOS33} [get_ports {QB[7]}]
