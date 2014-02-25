<?php
// $Id: sres.inc,v 1.44.2.10 2010/12/03 23:14:04 bardar Exp $


/**
 * autocomplete place field anywhere
 *  
 */
function sres_place_autocomplete($string = '') {  
  $matches = array();
  if ($string) {
    $result = db_query_range("SELECT field_sres_rs_address_place_value FROM {content_type_sres_realesate} WHERE LOWER(field_sres_rs_address_place_value) LIKE LOWER('%%%s%%')", $string, 0, 10);
    while ($node = db_fetch_object($result)) {
      $matches[$node->field_sres_rs_address_place_value] = check_plain($node->field_sres_rs_address_place_value);
    }
  }
  drupal_json($matches);
}

/**
 * inherit fields form sres_realestate type 
 * 
 */
function sres_inherit_from_rs() { 
  $result = db_query("SELECT field_sres_rs_grag_cap_value , field_sres_rs_grag_spcl_value , field_sres_rs_san_type_value , field_sres_rs_owall_scur_value , field_sres_rs_owall_doors_value  , field_sres_rs_owall_ex_value , field_sres_rs_cyard_grdn_value , field_sres_rs_cyard_grond_value  , field__sres_rs_cyard_area_value ,field_sres_rs_cyard_spcl_value  FROM {content_type_sres_realesate} c WHERE c.nid = %s", 48);
  $sres_rs_html;
  while ($node = db_fetch_object($result)) {
    $sres_rs_html = "<div id='sres_rs_services'>";
    $sres_rs_html = $sres_rs_html."<div id='field_sres_rs_grag_cap_value' >".$node->field_sres_rs_grag_cap_value."</div>";
    $sres_rs_html = $sres_rs_html."<div id='field_sres_rs_grag_spcl_value' >".$node->field_sres_rs_grag_spcl_value."</div>";
    $sres_rs_html = $sres_rs_html."<div id='field_sres_rs_san_type_value' >".$node->field_sres_rs_san_type_value."</div>";
    $sres_rs_html = $sres_rs_html."<div id='field_sres_rs_owall_scur_value' >".$node->field_sres_rs_owall_scur_value."</div>";
    $sres_rs_html = $sres_rs_html."<div id='field_sres_rs_owall_doors_value' >".$node->field_sres_rs_owall_doors_value."</div>";
    $sres_rs_html = $sres_rs_html."<div id='field_sres_rs_owall_ex_value' >".$node->field_sres_rs_owall_ex_value."</div>";
    $sres_rs_html = $sres_rs_html."<div id='field_sres_rs_cyard_grdn_value' >".$node->field_sres_rs_cyard_grdn_value."</div>";
    $sres_rs_html = $sres_rs_html."<div id='field_sres_rs_cyard_grond_value' >".$node->field_sres_rs_cyard_grond_value."</div>";
    
    $sres_rs_html = $sres_rs_html."<div id='field__sres_rs_cyard_area_value' >".$node->field__sres_rs_cyard_area_value."</div>";
    $sres_rs_html = $sres_rs_html."<div id='field_sres_rs_cyard_spcl_value' >".$node->field_sres_rs_cyard_spcl_value."</div>";
    $sres_rs_html = $sres_rs_html."</div>";
  }  
  print $sres_rs_html;
}

function sres_home() {
  return "";
}

function sres_admin_settings(){
  return drupal_get_form('sres_settings_form');
}

function sres_ini_multi_steps() {
  return "Sres";
}
function sres_pricing_tab() {
  return "pricing_tab";
}


