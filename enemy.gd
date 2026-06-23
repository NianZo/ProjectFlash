extends Control

const MAX_HEALTH: int = 100
var health: int
var activeEnemy: Control

signal clicked

func setActiveEnemy(enemy: Control):
	activeEnemy = enemy

func _ready():
	health = MAX_HEALTH

func _process(delta: float):
	pass

func _gui_input(event: InputEvent):
	pass
	if event is InputEventMouseButton and event.button_index == MOUSE_BUTTON_LEFT and event.pressed:
		print("Clicked on enemy")
		clicked.emit(self)
	
func hit(damage: int):
	health -= damage
	if health < 0:
		health = 0
