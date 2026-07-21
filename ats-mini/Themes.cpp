#include "Common.h"
#include "Themes.h"
#include "Draw.h"

ColorTheme theme[] = {
  {
    "Light",
    0xF79E, // bg
    0x18C3, // text
    0x7B8D, // text_muted
    0xFA04, // text_warn
    0x7B8D, // smeter_icon
    0x2D48, // smeter_bar
    0xD000, // smeter_bar_plus
    0xD6DA, // smeter_bar_empty
    0xFD60, // save_icon
    0x481F, // stereo_icon
    0xD000, // rf_icon
    0x2D48, // rf_icon_conn
    0x18C3, // batt_voltage
    0x18C3, // batt_border
    0x2D48, // batt_full
    0xD000, // batt_low
    0x769F, // batt_charge
    0xE565, // batt_icon
    0xA380, // band_text
    0x7B8D, // mode_text
    0x7B8D, // mode_border
    0xD6BA, // box_bg
    0xF79E, // box_border
    0x2965, // box_text
    0xD000, // box_off_bg
    0xF81F, // box_off_text
    0x8410, // menu_bg
    0xED87, // menu_border
    0xEF7D, // menu_hdr
    0xCF3F, // menu_item
    0xFD60, // menu_hl_bg
    0x18C3, // menu_hl_text
    0xA65F, // menu_param
    0x18C3, // freq_text
    0xA380, // funit_text
    0xD000, // freq_hl
    0xD6A0, // freq_hl_sel
    0x1BBA, // rds_text
    0xC012, // scale_text
    0xD000, // scale_pointer
    0x2508, // scale_line
    0xC8F7, // scan_grid
    0x0659, // scan_snr
    0x2D48, // scan_rssi
  },

  {
    "Dark",
    0x0000, // bg
    0xDEFB, // text
    0xA514, // text_muted
    0xFA04, // text_warn
    0xA514, // smeter_icon
    0x2D48, // smeter_bar
    0xD000, // smeter_bar_plus
    0x2945, // smeter_bar_empty
    0xFD60, // save_icon
    0x8AFF, // stereo_icon
    0xD000, // rf_icon
    0x2D48, // rf_icon_conn
    0xDEFB, // batt_voltage
    0xDEFB, // batt_border
    0x2D48, // batt_full
    0xD000, // batt_low
    0x057F, // batt_charge
    0xFDE6, // batt_icon
    0xDCC0, // band_text
    0xA514, // mode_text
    0xA514, // mode_border
    0x1140, // box_bg
    0x0000, // box_border
    0xC618, // box_text
    0x31E0, // box_off_bg
    0xA514, // box_off_text
    0x0289, // menu_bg
    0xED87, // menu_border
    0xEF7D, // menu_hdr
    0xAEDF, // menu_item
    0xDCA0, // menu_hl_bg
    0x18C3, // menu_hl_text
    0xA65F, // menu_param
    0xDEFB, // freq_text
    0xDCC0, // funit_text
    0xD000, // freq_hl
    0xD6A0, // freq_hl_sel
    0xFBE0, // rds_text
    0xE015, // scale_text
    0xD000, // scale_pointer
    0x364A, // scale_line
    0x2945, // scan_grid
    0x0659, // scan_snr
    0x2D48, // scan_rssi
  }
};

uint8_t themeIdx = 0;
int getTotalThemes() { return ITEM_COUNT(theme); }

// Turn theme editor on (1) or off (0), or get current status (2)
bool switchThemeEditor(int8_t state) {
  static bool themeEditor = false;
  themeEditor = state == 0 ? false : state == 1 ? true : themeEditor;
  return themeEditor;
}