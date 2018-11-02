package roman

import "testing"

func TestIntToRoman(t *testing.T) {

	tests := map[int]string{
		1:    "I",
		2:    "II",
		3:    "III",
		4:    "IV",
		5:    "V",
		6:    "VI",
		7:    "VII",
		8:    "VIII",
		9:    "IX",
		10:   "X",
		20:   "XX",
		40:   "XL",
		49:   "XLIX",
		50:   "L",
		90:   "XC",
		94:   "XCIV",
		100:  "C",
		400:  "CD",
		500:  "D",
		900:  "CM",
		1000: "M",
		3999: "MMMCMXCIX",
		4000: "",
	}

	for input, want := range tests {
		actual := toRoman(input)
		if want != actual {
			t.Errorf("Wanted '%s' for %d, got '%s'", want, input, actual)
		}
	}
}
