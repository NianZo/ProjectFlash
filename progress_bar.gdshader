shader_type canvas_item;

instance uniform vec4 baseColor : source_color;
instance uniform float progress;

void vertex() {
	// Called for every vertex the material is visible on.
}

void fragment() {
	// Called for every pixel the material is visible on.
	if (UV.x <= progress) {
		COLOR = baseColor;
	} else {
		COLOR = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	}
}

//void light() {
//	// Called for every pixel for every light affecting the CanvasItem.
//	// Uncomment to replace the default light processing function with this one.
//}
