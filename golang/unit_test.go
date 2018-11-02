package unit

import "testing"

func TestLifeTheUniveresAndEverything(t *testing.T) {
	result := answer()
	if result != 42 {
		t.Errorf("Expected 42, got %d", result)
	}
}
