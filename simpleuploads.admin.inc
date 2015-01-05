<?php
/**
 * @file
 * Provide a settings form for the simpleuploads module.
 */

/**
 * Provide a settings form for the module.
 */
function simpleuploads_settings_form() {
  $form = array();

  $options = array();
  // Probably safe to assume it would always be enabled?
  if (module_exists('image')) {
    $styles = image_styles();
    if (count($styles)) {
      foreach ($styles as $key => $style){
        $options[$key] = $style['label'];
      }
    }
  }

  $none = array('none' => t('None'));
  $options = $none + $options;
  $form['simpleuploads_imagestyle'] = array(
    '#type' => 'select',
    '#title' => t('Image Style'),
    '#options' => $options,
    '#default_value' => variable_get('simpleuploads_imagestyle', 'none'),
    '#description' => t('An image style to apply to inline images added to ckeditor using the simpleuploads plugin.'),
  );

  $form['simpleuploads_uploaddir'] = array(
    '#type' => 'textfield',
    '#title' => t('Upload directory'),
    '#default_value' => variable_get('simpleuploads_uploaddir', 'uploads/'),
    '#description' => t('An optional subdirectory within the /files directory to upload files to (make sure to create it). To upload to the root /files directory leave it blank.'),
  );

  return system_settings_form($form);
}
