extends Control

const MAX_HEALTH: int = 100
var health: int
var activeEnemy: Control
var alive: bool

signal clicked

func setActiveEnemy(enemy: Control):
	activeEnemy = enemy

func _ready():
	health = MAX_HEALTH
	alive = true
	$RespawnTimer.set_wait_time(10.0) 
	$RespawnTimer.set_one_shot(true)
	$RespawnTimer.timeout.connect(respawn)

func _process(delta: float):
	pass
	$Sprite.visible = alive

func _gui_input(event: InputEvent):
	pass
	if event is InputEventMouseButton and event.button_index == MOUSE_BUTTON_LEFT and event.pressed:
		print("Clicked on enemy")
		clicked.emit(self)
	
func hit(damage: int):
	health -= damage
	if health <= 0:
		health = 0
		alive = false
		self.mouse_filter = Control.MOUSE_FILTER_IGNORE
		$RespawnTimer.start()

func respawn():
	pass
	alive = true
	health = MAX_HEALTH
	self.mouse_filter = Control.MOUSE_FILTER_STOP
