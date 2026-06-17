extends Control

const MAX_HEALTH: int = 100
var health: int
var activeEnemy: Control

signal clicked

func setActiveEnemy(enemy: Control):
	activeEnemy = enemy

func onClicked():
	clicked.emit(self)

func _ready():
	health = MAX_HEALTH
	$HealthBar.set_instance_shader_parameter("baseColor", Vector4(1.0, 0.0, 0.0, 1.0))
	$HealthBar.set_instance_shader_parameter("progress", health * 1.0 / MAX_HEALTH)
	$Area2D.clicked.connect(onClicked)
	pass

func _process(delta: float):
	pass
	$HealthBar.set_instance_shader_parameter("progress", health * 1.0 / MAX_HEALTH)

func _gui_input(event: InputEvent):
	pass
	if event is InputEventMouseButton and event.button_index == MOUSE_BUTTON_LEFT and event.pressed:
		print("Clicked on enemy")
		clicked.emit(self)
	
func hit(damage: int):
	health -= damage
	if health < 0:
		health = 0
