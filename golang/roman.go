package roman

func toRoman(src int) string {

	if src > 3999 {
		return ""
	}

	digits := [...]Digit{
		{1, "I"},
		{4, "IV"},
		{5, "V"},
		{9, "IX"},
		{10, "X"},
		{40, "XL"},
		{50, "L"},
		{90, "XC"},
		{100, "C"},
		{400, "CD"},
		{500, "D"},
		{900, "CM"},
		{1000, "M"},
	}

	roman := ""
	current := src
	for i := len(digits) - 1; i >= 0; i-- {
		d := digits[i]
		for d.Value <= current {
			roman += d.Representation
			current -= d.Value
		}
	}

	return roman
}
