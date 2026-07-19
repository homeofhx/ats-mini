#include "Common.h"
#include "Storage.h"
#include "Themes.h"
#include "Utils.h"
#include "Draw.h"
#include <LittleFS.h>
#include <nvs.h>
#include <nvs_flash.h>

static void drawAboutCommon() {
    spr.setTextDatum(TL_DATUM);
    spr.setTextColor(TH.text_muted);
    spr.drawString(RECEIVER_DESC, 0, 0, 4);
    spr.setTextColor(TH.text);
    spr.drawString(getVersion(), 2, 25, 2);
}

// Show SYSTEM screen
static void drawAboutSystem() {
    drawAboutCommon();

    char text[100];
    sprintf(text,
            "CPU: %s r%i, %lu MHz",
            ESP.getChipModel(),
            ESP.getChipRevision(),
            ESP.getCpuFreqMHz());
    spr.drawString(text, 2, 70 + 16 * -1, 2);

    sprintf(text,
            "FLASH: %luM, %luk (%luk), FS %luk (%luk)",
            ESP.getFlashChipSize() / (1024U * 1024U),
            ESP.getFreeSketchSpace() / 1024U,
            (ESP.getFreeSketchSpace() - ESP.getSketchSize()) / 1024U,
            (unsigned long) LittleFS.totalBytes() / 1024U,
            (unsigned long) (LittleFS.totalBytes() - LittleFS.usedBytes()) / 1024U);
    spr.drawString(text, 2, 70 + 16 * 0, 2);

    nvs_stats_t nvs_stats;
    nvs_get_stats(STORAGE_PARTITION, &nvs_stats);
    sprintf(text,
            "NVS: TOTAL %u, USED %u, FREE %u",
            nvs_stats.total_entries,
            nvs_stats.used_entries,
            nvs_stats.free_entries);
    spr.drawString(text, 2, 70 + 16 * 1, 2);

    sprintf(text,
            "MEM: HEAP %luk (%luk), PSRAM %luk (%luk)",
            ESP.getHeapSize() / 1024U, ESP.getFreeHeap() / 1024U,
            ESP.getPsramSize() / 1024U, ESP.getFreePsram() / 1024U);
    spr.drawString(text, 2, 70 + 16 * 2, 2);

    sprintf(text,
            "Display ID: %08lX, STAT: %02X%08lX",
#if !defined(LILYGO_SI473X)
        tft.readcommand32(ST7789_RDDID, 1),
        tft.readcommand8(ST7789_RDDST, 1),
        tft.readcommand32(ST7789_RDDST, 2)
#else
        0, 0, 0
#endif
    );
    spr.drawString(text, 2, 70 + 16 * 3, 2);

    char *ip = getWiFiIPAddress();
    sprintf(text, "WiFi MAC: %s%s%s", getMACAddress(), *ip ? ", IP: " : "", *ip ? ip : "");
    spr.drawString(text, 2, 70 + 16 * 4, 2);

    for (int i = 0; i < 8; i++) {
        uint16_t rgb = (i & 1 ? 0x001F : 0) | (i & 2 ? 0x07E0 : 0) | (i & 4 ? 0xF800 : 0);
        spr.fillRect(i * 40, 160, 40, 20, rgb);
    }

    spr.pushSprite(0, 0);
}

// Draw ABOUT screens
void drawAbout() {
    drawAboutSystem();
}