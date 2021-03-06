#ifndef H265_PARSER_H_
#define H265_PARSER_H_

#include <stdint.h>

struct NalUnitHeader {
  enum H265NalType nal_unit_type;
  uint8_t nuh_layer_id;
  uint8_t nuh_temporal_id_plus1;
};

struct H265VideoParameterSet {
  uint8_t vps_video_parameter_set_id;
  uint8_t vps_base_layer_internal_flag;
  uint8_t vps_base_layer_available_flag;
  uint8_t vps_max_layers_minus1;
  uint8_t vps_max_sub_layers_minus1;
  uint8_t vps_temporal_id_nesting_flag;
  uint16_t vps_reserved_0xffff_16bits;
  uint8_t vps_sub_layer_ordering_info_present_flag;
  uint8_t vps_max_layer_id;
  uint16_t vps_num_layer_sets_minus1;
  uint8_t vps_timing_info_present_flag;
  uint32_t vps_num_units_in_tick;
  uint8_t vps_time_scale;
  uint8_t vps_poc_proportional_to_timing_flag;
  uint32_t vps_num_ticks_poc_diff_one_minus1;
  uint32_t vps_num_hrd_parameters;
  uint8_t vps_extension_flag;
};

struct H265PicParameterSet {
  uint32_t pps_pic_parameter_set_id;
  uint32_t pps_seq_parameter_set_id;
  uint8_t dependent_slice_segments_enabled_flag;
  uint8_t output_flag_present_flag;
  uint8_t num_extra_slice_header_bits;
  uint8_t sign_data_hiding_enabled_flag;
  uint8_t cabac_init_present_flag;
  uint32_t num_ref_idx_l0_default_active_minus1;
  uint32_t num_ref_idx_l1_default_active_minus1;
  int32_t init_qp_minus26;
  uint8_t constrained_intra_pred_flag;
  uint8_t transform_skip_enabled_flag;
  uint8_t cu_qp_delta_enabled_flag;
  uint32_t diff_cu_qp_delta_depth;
  int32_t pps_cb_qp_offset;
  int32_t pps_cr_qp_offset;
  uint8_t pps_slice_chroma_qp_offsets_present_flag;
  uint8_t weighted_pred_flag;
  uint8_t weighted_bipred_flag;
  uint8_t transquant_bypass_enabled_flag;
  uint8_t tiles_enabled_flag;
  uint8_t entropy_coding_sync_enabled_flag;
  uint32_t num_tile_columns_minus1;
  uint32_t num_tile_rows_minus1;
  uint8_t uniform_spacing_flag;
  uint8_t loop_filter_across_tiles_enabled_flag;
  uint8_t pps_loop_filter_across_slices_enabled_flag;
  uint8_t deblocking_filter_control_present_flag;
  uint8_t deblocking_filter_override_enabled_flag;
  uint8_t pps_deblocking_filter_disabled_flag;
  int32_t pps_beta_offset_div2;
  int32_t pps_tc_offset_div2;
  uint8_t pps_scaling_list_data_present_flag;
  uint8_t lists_modification_present_flag;
  uint32_t log2_parallel_merge_level_minus2;
  uint8_t slice_segment_header_extension_present_flag;
  uint8_t pps_extension_present_flag;
  uint8_t pps_range_extension_flag;
  uint8_t pps_multilayer_extension_flag;
  uint8_t pps_extension_6bits;
  uint8_t pps_extension_data_flag;

  // pps_range_extension
  uint32_t log2_max_transform_skip_block_size_minus2;
  uint8_t cross_component_prediction_enabled_flag;
  uint8_t chroma_qp_offset_list_enabled_flag;
  uint32_t diff_cu_chroma_qp_offset_depth;
  uint32_t chroma_qp_offset_list_len_minus1;
  uint32_t log2_sao_offset_scale_luma;
  uint32_t log2_sao_offset_scale_chroma;
};

struct H265HrdParameters {
  uint8_t nal_hrd_parameters_present_flag;
  uint8_t vcl_hrd_parameters_present_flag;
  uint8_t sub_pic_hrd_params_present_flag;
  uint8_t tick_divisor_minus2;
  uint8_t du_cpb_removal_delay_increment_length_minus1;
  uint8_t sub_pic_cpb_params_in_pic_timing_sei_flag;
  uint8_t dpb_output_delay_du_length_minus1;
  uint8_t bit_rate_scale;
  uint8_t cpb_size_scale;
  uint8_t cpb_size_du_scale;
  uint8_t initial_cpb_removal_delay_length_minus1;
  uint8_t au_cpb_removal_delay_length_minus1;
  uint8_t dpb_output_delay_length_minus1;
  uint8_t fixed_pic_rate_general_flag;
  uint8_t fixed_pic_rate_within_cvs_flag;
  uint32_t elemental_duration_in_tc_minus1;
  uint8_t low_delay_hrd_flag;
  uint32_t cpb_cnt_minus1;
};

struct H265VuiParameters {
  uint8_t aspect_ratio_info_present_flag;
  uint8_t aspect_ratio_idc;
  uint16_t sar_width;
  uint16_t sar_height;
  uint8_t overscan_info_present_flag;
  uint8_t overscan_appropriate_flag;
  uint8_t video_signal_type_present_flag;
  uint8_t video_format;
  uint8_t video_full_range_flag;
  uint8_t colour_description_present_flag;
  uint8_t colour_primaries;
  uint8_t transfer_characteristics;
  uint8_t matrix_coeffs;
  uint8_t chroma_loc_info_present_flag;
  uint32_t chroma_sample_loc_type_top_field;
  uint32_t chroma_sample_loc_type_bottom_field;
  uint8_t neutral_chroma_indication_flag;
  uint8_t field_seq_flag;
  uint8_t frame_field_info_present_flag;
  uint8_t default_display_window_flag;
  uint32_t def_disp_win_left_offset;
  uint32_t def_disp_win_right_offset;
  uint32_t def_disp_win_top_offset;
  uint32_t def_disp_win_bottom_offset;
  uint8_t vui_timing_info_present_flag;
  uint32_t vui_num_units_in_tick;
  uint32_t vui_time_scale;
  uint8_t vui_poc_proportional_to_timing_flag;
  uint32_t vui_num_ticks_poc_diff_one_minus1;
  uint8_t vui_hrd_parameters_present_flag;
  uint8_t bitstream_restriction_flag;
  uint8_t tiles_fixed_structure_flag;
  uint8_t motion_vectors_over_pic_boundaries_flag;
  uint8_t restricted_ref_pic_lists_flag;
  uint32_t min_spatial_segmentation_idc;
  uint32_t max_bytes_per_pic_denom;
  uint32_t max_bits_per_min_cu_denom;
  uint32_t log2_max_mv_length_horizontal;
  uint32_t log2_max_mv_length_vertical;
  struct H265HrdParameters hrd_parameters;
};

struct H265SeqParameterSet {
  uint32_t sps_video_parameter_set_id;
  uint8_t sps_max_sub_layers_minus1;
  uint32_t sps_temporal_id_nesting_flag;
  uint8_t sps_seq_parameter_set_id;
  uint8_t chroma_format_idc;
  uint32_t separate_colour_plane_flag;
  uint8_t pic_width_in_luma_samples;
  uint8_t pic_height_in_luma_samples;
  uint32_t conformance_window_flag;
  uint8_t conf_win_left_offset;
  uint8_t conf_win_right_offset;
  uint8_t conf_win_top_offset;
  uint8_t conf_win_bottom_offset;
  uint8_t bit_depth_luma_minus8;
  uint8_t bit_depth_chroma_minus8;
  uint8_t log2_max_pic_order_cnt_lsb_minus4;
  uint32_t sps_sub_layer_ordering_info_present_flag;
  uint8_t log2_min_luma_coding_block_size_minus3;
  uint8_t log2_diff_max_min_luma_coding_block_size;
  uint8_t log2_min_luma_transform_block_size_minus2;
  uint8_t log2_diff_max_min_luma_transform_block_size;
  uint8_t max_transform_hierarchy_depth_inter;
  uint8_t max_transform_hierarchy_depth_intra;
  uint32_t scaling_list_enabled_flag;
  uint32_t sps_scaling_list_data_present_flag;
  uint32_t amp_enabled_flag;
  uint32_t sample_adaptive_offset_enabled_flag;
  uint32_t pcm_enabled_flag;
  uint32_t pcm_sample_bit_depth_luma_minus1;
  uint32_t pcm_sample_bit_depth_chroma_minus1;
  uint8_t log2_min_pcm_luma_coding_block_size_minus3;
  uint8_t log2_diff_max_min_pcm_luma_coding_block_size;
  uint32_t pcm_loop_filter_disabled_flag;
  uint32_t num_short_term_ref_pic_sets;
  uint32_t long_term_ref_pics_present_flag;
  uint8_t num_long_term_ref_pics_sps;
  uint32_t sps_temporal_mvp_enabled_flag;
  uint32_t strong_intra_smoothing_enabled_flag;
  uint32_t vui_parameters_present_flag;
  uint32_t sps_extension_present_flag;
  struct H265VuiParameters vui_param;

  // variables
  // P73
  uint8_t ChromaArrayType;

  // P20 Table 6-1
  uint8_t SubWidthC;
  uint8_t SubHeightC;

  // P74, (7-10) ~ (7-22)
  uint32_t MinCbLog2SizeY;
  uint32_t CtbLog2SizeY;
  uint32_t MinCbSizeY;
  uint32_t CtbSizeY;
  uint32_t PicWidthInMinCbsY;
  uint32_t PicWidthInCtbsY;
  uint32_t PicHeightInMinCbsY;
  uint32_t PicHeightInCtbsY;
  uint32_t PicSizeInMinCbsY;
  uint32_t PicSizeInCtbsY;
  uint32_t PicSizeInSamplesY;
  uint32_t PicWidthInSamplesC;
  uint32_t PicHeightInSamplesC;
};

struct H265ProfileTierLevelSubLayer {
  uint8_t profile_present_flag;
  uint8_t level_present_flag;
  uint8_t profile_space;
  uint8_t tier_flag;
  uint8_t profile_idc;
  uint8_t profile_compatibility_flag[32];
  uint8_t progressive_source_flag;
  uint8_t interlaced_source_flag;
  uint8_t non_packed_constraint_flag;
  uint8_t frame_only_constraint_flag;
  uint8_t max_12bit_constraint_flag;
  uint8_t max_10bit_constraint_flag;
  uint8_t max_8bit_constraint_flag;
  uint8_t max_422chroma_constraint_flag;
  uint8_t max_420chroma_constraint_flag;
  uint8_t max_monochrome_constraint_flag;
  uint8_t intra_constraint_flag;
  uint8_t one_picture_only_constraint_flag;
  uint8_t lower_bit_rate_constraint_flag;
  uint8_t inbld_flag;
  uint8_t level_idc;
};

struct H265SliceSegmentHeader {
  uint8_t first_slice_segment_in_pic_flag;
  uint8_t no_output_of_prior_pics_flag;
  uint32_t slice_pic_parameter_set_id;
  uint8_t dependent_slice_segment_flag;
  uint8_t slice_segment_address;
  uint32_t slice_type;
  uint8_t pic_output_flag;
  uint8_t colour_plane_id;
  uint8_t slice_pic_order_cnt_lsb;
  uint8_t short_term_ref_pic_set_sps_flag;
  uint8_t short_term_ref_pic_set_idx;
  uint32_t num_long_term_sps;
  uint32_t num_long_term_pics;
  uint8_t slice_temporal_mvp_enabled_flag;
  uint8_t slice_sao_luma_flag;
  uint8_t slice_sao_chroma_flag;
  uint8_t num_ref_idx_active_override_flag;
  uint32_t num_ref_idx_l0_active_minus1;
  uint32_t num_ref_idx_l1_active_minus1;
  uint8_t mvd_l1_zero_flag;
  uint8_t cabac_init_flag;
  uint8_t collocated_from_l0_flag;
  uint32_t collocated_ref_idx;
  uint32_t five_minus_max_num_merge_cand;
  int32_t slice_qp_delta;
  int32_t slice_cb_qp_offset;
  int32_t slice_cr_qp_offset;
  uint8_t cu_chroma_qp_offset_enabled_flag;
  uint8_t deblocking_filter_override_flag;
  uint8_t slice_deblocking_filter_disabled_flag;
  int32_t slice_beta_offset_div2;
  int32_t slice_tc_offset_div2;
  uint8_t slice_loop_filter_across_slices_enabled_flag;
  uint32_t num_entry_point_offsets;
  uint32_t offset_len_minus1;
  uint32_t slice_segment_header_extension_length;
};

struct H265SliceSegmentLayer {
  struct H265SliceSegmentHeader header;
};

#endif
