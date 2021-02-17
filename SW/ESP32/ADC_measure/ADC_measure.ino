#include <esp_adc_cal.h>
#include <driver/adc.h>
#include <esp_adc_cal.h>

// Potentiometer is connected to GPIO 34 (Analog ADC1_CH6) 

  #define V_REF 1100  // ADC reference voltage
  esp_adc_cal_characteristics_t characteristics;
void setup() {
  Serial.begin(115200);
  delay(1000);


  // Configure ADC
  adc1_config_width(ADC_WIDTH_12Bit);
  adc1_config_channel_atten(ADC1_CHANNEL_6, ADC_ATTEN_11db);

  // Calculate ADC characteristics i.e. gain and offset factors
  esp_adc_cal_get_characteristics(V_REF, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, &characteristics);

   esp_err_t status = adc_vref_to_gpio(ADC_UNIT_1, GPIO_NUM_25);
    if (status == ESP_OK) {
        printf("v_ref routed to GPIO\n");
    } else {
        printf("failed to route v_ref\n");
    }

}

void loop() {   
  uint32_t voltage = adc1_to_voltage(ADC1_CHANNEL_6, &characteristics);
  Serial.println(voltage);
  delay(500);
}
