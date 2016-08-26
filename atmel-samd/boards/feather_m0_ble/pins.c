#include "pins.h"
#include "asf/sam0/drivers/system/system.h"

PIN(PA02, true, ADC_POSITIVE_INPUT_PIN0);
PIN(PB08, true, ADC_POSITIVE_INPUT_PIN8);
PIN(PB09, true, ADC_POSITIVE_INPUT_PIN9);
PIN(PA04, true, ADC_POSITIVE_INPUT_PIN4);
PIN(PA05, true, ADC_POSITIVE_INPUT_PIN5);
PIN(PB02, true, ADC_POSITIVE_INPUT_PIN10);
PIN(PB11, false, NO_ADC_INPUT);
PIN(PB10, false, NO_ADC_INPUT);
PIN(PA12, false, NO_ADC_INPUT);
PIN(PA11, true, ADC_POSITIVE_INPUT_PIN19);
PIN(PA10, true, ADC_POSITIVE_INPUT_PIN18);
PIN(PA22, false, NO_ADC_INPUT);
PIN(PA23, false, NO_ADC_INPUT);
PIN(PA15, false, NO_ADC_INPUT);
PIN(PA20, false, NO_ADC_INPUT);
PIN(PA07, true, ADC_POSITIVE_INPUT_PIN7);
PIN(PA18, false, NO_ADC_INPUT);
PIN(PA16, false, NO_ADC_INPUT);
PIN(PA19, false, NO_ADC_INPUT);
PIN(PA17, false, NO_ADC_INPUT);

STATIC const mp_map_elem_t pin_cpu_pins_locals_dict_table[] = {
  { MP_OBJ_NEW_QSTR(MP_QSTR_PA02), (mp_obj_t)&pin_PA02 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_PB08), (mp_obj_t)&pin_PB08 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_PB09), (mp_obj_t)&pin_PB09 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_PA04), (mp_obj_t)&pin_PA04 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_PA05), (mp_obj_t)&pin_PA05 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_PB02), (mp_obj_t)&pin_PB02 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_PB11), (mp_obj_t)&pin_PB11 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_PB10), (mp_obj_t)&pin_PB10 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_PA12), (mp_obj_t)&pin_PA12 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_PA11), (mp_obj_t)&pin_PA11 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_PA10), (mp_obj_t)&pin_PA10 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_PA22), (mp_obj_t)&pin_PA22 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_PA23), (mp_obj_t)&pin_PA23 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_PA15), (mp_obj_t)&pin_PA15 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_PA20), (mp_obj_t)&pin_PA20 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_PA07), (mp_obj_t)&pin_PA07 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_PA18), (mp_obj_t)&pin_PA18 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_PA16), (mp_obj_t)&pin_PA16 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_PA19), (mp_obj_t)&pin_PA19 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_PA17), (mp_obj_t)&pin_PA17 },
};
MP_DEFINE_CONST_DICT(pin_cpu_pins_locals_dict, pin_cpu_pins_locals_dict_table);

STATIC const mp_map_elem_t pin_board_pins_locals_dict_table[] = {
  { MP_OBJ_NEW_QSTR(MP_QSTR_A0), (mp_obj_t)&pin_PA02 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_A1), (mp_obj_t)&pin_PB08 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_A2), (mp_obj_t)&pin_PB09 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_A3), (mp_obj_t)&pin_PA04 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_A4), (mp_obj_t)&pin_PA05 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_A5), (mp_obj_t)&pin_PB02 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_SCK), (mp_obj_t)&pin_PB11 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_MOSI), (mp_obj_t)&pin_PB10 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_MISO), (mp_obj_t)&pin_PA12 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_0RX), (mp_obj_t)&pin_PA11 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_1TX), (mp_obj_t)&pin_PA10 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_SDA), (mp_obj_t)&pin_PA22 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_SCL), (mp_obj_t)&pin_PA23 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_D5), (mp_obj_t)&pin_PA15 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_D6), (mp_obj_t)&pin_PA20 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_D9), (mp_obj_t)&pin_PA07 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_D10), (mp_obj_t)&pin_PA18 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_D11), (mp_obj_t)&pin_PA16 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_D12), (mp_obj_t)&pin_PA19 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_D13), (mp_obj_t)&pin_PA17 },
};
MP_DEFINE_CONST_DICT(pin_board_pins_locals_dict, pin_board_pins_locals_dict_table);
