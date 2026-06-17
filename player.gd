extends Control

const MAX_HEALTH: int = 100
var health: int
var activeEnemy: Control = null

var targetPosition: Vector2
const SPEED: float = 200

func stepTowardsTarget(delta: float):
	var travelVector: Vector2 = targetPosition - $Sprite.position
	if travelVector.length() < SPEED * delta:
		$Sprite.position = targetPosition
		return
	$Sprite.position = $Sprite.position + travelVector.normalized() * SPEED * delta

func setActiveEnemy(enemy: Control):
	activeEnemy = enemy
	print("Set Active enemy")

func _ready():
	health = MAX_HEALTH
	$HealthBar.set_instance_shader_parameter("baseColor", Vector4(1.0, 0.0, 0.0, 1.0))
	$HealthBar.set_instance_shader_parameter("progress", health * 1.0 / MAX_HEALTH)
	$AttackButton1.pressed.connect(onAttackButton1Pressed)
	
	targetPosition = $Sprite.position
	pass

func _process(delta: float):
	pass
	$HealthBar.set_instance_shader_parameter("progress", health * 1.0 / MAX_HEALTH)
	stepTowardsTarget(delta)

func onAttackButton1Pressed():
	pass
	if activeEnemy:
		activeEnemy.hit(5)

func move(newPosition: Vector2):
	targetPosition = newPosition
