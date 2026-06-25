extends Control

const MAX_HEALTH: int = 100
var health: int
var activeEnemy: Control = null

var targetPosition: Vector2
const SPEED: float = 200

func stepTowardsTarget(delta: float):
	var travelVector: Vector2 = targetPosition - position
	if travelVector.length() < SPEED * delta:
		position = targetPosition
		return
	position = position + travelVector.normalized() * SPEED * delta

func setActiveEnemy(enemy: Control):
	activeEnemy = enemy
	print("Set Active enemy")

func _ready():
	health = MAX_HEALTH
	targetPosition = position

func _process(delta: float):
	stepTowardsTarget(delta)
	if activeEnemy and !activeEnemy.alive:
		activeEnemy = null

func onAttackButton1Pressed():
	if activeEnemy:
		activeEnemy.hit(5)

func move(newPosition: Vector2):
	targetPosition = newPosition
