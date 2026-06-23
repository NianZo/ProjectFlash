extends Control

func onEnemyClicked(enemy: Control):
	$Player.setActiveEnemy(enemy)

func _ready():
	$Enemy.clicked.connect(onEnemyClicked)
	self.gui_input.connect(onMapClicked)
	$AttackButton1.pressed.connect(onAttackButton1Pressed)
	
	$PlayerHealthBar.set_instance_shader_parameter("baseColor", Vector4(1.0, 0.0, 0.0, 1.0))
	$PlayerHealthBar.set_instance_shader_parameter("progress", $Player.health * 1.0 / $Player.MAX_HEALTH)
	
	$EnemyHealthBar.set_instance_shader_parameter("baseColor", Vector4(1.0, 0.0, 0.0, 1.0))
	$EnemyHealthBar.set_instance_shader_parameter("progress", $Enemy.health * 1.0 / $Enemy.MAX_HEALTH)

func _process(delta: float):
	$PlayerHealthBar.set_instance_shader_parameter("progress", $Player.health * 1.0 / $Player.MAX_HEALTH)
	$EnemyHealthBar.set_instance_shader_parameter("progress", $Enemy.health * 1.0 / $Enemy.MAX_HEALTH)

func onMapClicked():
	$Player.move(get_global_mouse_position())
	
func _gui_input(event: InputEvent):
	if event is InputEventMouseButton and event.button_index == MOUSE_BUTTON_LEFT and event.pressed:
		print("Clicked on environment")
		$Player.move(get_global_mouse_position())

func onAttackButton1Pressed():
	$Player.onAttackButton1Pressed()
