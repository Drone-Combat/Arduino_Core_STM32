{% if type == "ll" %}
/* LL raised several warnings, ignore them */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

{% endif %}
{% for serie in serieslist %}
  {% if loop.first %}
#ifdef STM32{{serie.upper()}}xx
  {% else %}
#elif STM32{{serie.upper()}}xx
  {% endif %}
  {% if type == periph %}
  #include "stm32{{serie}}xx_{{type}}.c"
  {% else %}
  #include "stm32{{serie}}xx_{{type}}_{{periph}}.c"
  {% endif %}
  {% if loop.last %}
#endif
  {% endif %}
{% endfor %}
{% if type == "ll" %}
#pragma GCC diagnostic pop
{% endif %}

