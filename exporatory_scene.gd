extends Control

func onEnemyClicked(enemy: Control):
	pass
	$Player.setActiveEnemy(enemy)

func _ready():
	$Enemy.clicked.connect(onEnemyClicked)
	self.gui_input.connect(onMapClicked)

func onMapClicked():
	pass
	$Player.move(get_global_mouse_position())
	
func _gui_input(event: InputEvent):
	pass
	if event is InputEventMouseButton and event.button_index == MOUSE_BUTTON_LEFT and event.pressed:
		print("Clicked on environment")
		$Player.move(get_global_mouse_position())
#func _input(event):
	#if event is InputEventMouseButton and event.button_index == MOUSE_BUTTON_LEFT:
	#	$Player.move(get_global_mouse_position())
