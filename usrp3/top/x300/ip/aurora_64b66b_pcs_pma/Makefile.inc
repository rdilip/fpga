#
# Copyright 2016 Ettus Research
#

include $(TOOLS_DIR)/make/viv_ip_builder.mak

AURORA_PHY_SRCS = \
$(IP_DIR)/aurora_64b66b_pcs_pma/aurora_phy_x1.v \
$(IP_DIR)/aurora_64b66b_pcs_pma/aurora_phy_clk_gen.v \
$(IP_DIR)/aurora_64b66b_pcs_pma/aurora_axis_mac.v \
$(IP_AURORA_64B66B_PCS_PMA_EXAMPLE_SRCS)

IP_AURORA_64B66B_PCS_PMA_EXAMPLE_SRCS = $(addprefix $(IP_BUILD_DIR)/aurora_64b66b_pcs_pma_example/aurora_64b66b_pcs_pma_example.srcs/, \
sources_1/imports/example_design/support/aurora_64b66b_pcs_pma_clock_module.v \
sources_1/imports/example_design/support/aurora_64b66b_pcs_pma_gt_common_wrapper.v \
sources_1/imports/example_design/support/aurora_64b66b_pcs_pma_support_reset_logic.v \
sources_1/imports/example_design/support/aurora_64b66b_pcs_pma_support.v \
sources_1/imports/example_design/aurora_64b66b_pcs_pma_cdc_sync_exdes.v \
sources_1/imports/example_design/aurora_64b66b_pcs_pma_example_axi_to_ll.v \
sources_1/imports/example_design/aurora_64b66b_pcs_pma_example_ll_to_axi.v \
)

IP_AURORA_64B66B_PCS_PMA_SRCS = $(IP_BUILD_DIR)/aurora_64b66b_pcs_pma/aurora_64b66b_pcs_pma.xci

IP_AURORA_64B66B_PCS_PMA_OUTS = $(addprefix $(IP_BUILD_DIR)/aurora_64b66b_pcs_pma/, \
aurora_64b66b_pcs_pma.xci.out \
) 

$(IP_AURORA_64B66B_PCS_PMA_SRCS) $(IP_AURORA_64B66B_PCS_PMA_OUTS) $(IP_AURORA_64B66B_PCS_PMA_EXAMPLE_SRCS): $(IP_DIR)/aurora_64b66b_pcs_pma/aurora_64b66b_pcs_pma.xci
	$(call BUILD_VIVADO_IP,aurora_64b66b_pcs_pma,$(ARCH),$(PART_ID),$(IP_DIR),$(IP_BUILD_DIR),1)
