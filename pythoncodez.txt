import random

class Player:
    def __init__(self, name, health=100, damage=10):
        self.name = name
        self.health = health
        self.damage = damage

    def attack(self, other_player):
        damage_dealt = random.randint(1, self.damage)
        other_player.health -= damage_dealt
        print(f"{self.name} attacked {other_player.name} and dealt {damage_dealt} damage.")

    def display_info(self):
        print(f"{self.name} - Health: {self.health}")

class Game:
    def __init__(self):
        self.players = []

    def add_player(self, player):
        self.players.append(player)

    def player_list(self):
        print("Current Players:")
        for player in self.players:
            player.display_info()

    def start_battle(self):
        if len(self.players) < 2:
            print("Need at least 2 players to start a battle.")
            return

        print("Battle Started!")
        while any(player.health > 0 for player in self.players):
            attacker = random.choice(self.players)
            defender = random.choice([player for player in self.players if player != attacker])

            attacker.attack(defender)
            self.player_list()

        print("Battle Ended!")

if __name__ == "__main__":
    game = Game()

    # Create players
    player1 = Player("Player 1")
    player2 = Player("Player 2")
    player3 = Player("Player 3")

    # Add players to the game
    game.add_player(player1)
    game.add_player(player2)
    game.add_player(player3)

    # Display player list
    game.player_list()

    # Start the battle
    game.start_battle()
import random

class Player:
    def __init__(self, name, health=100, damage=10):
        self.name = name
        self.health = health
        self.damage = damage
        self.special_move_damage = 20  # Extra damage for special move
        self.special_move_available = True

    def attack(self, other_player):
        damage_dealt = random.randint(1, self.damage)
        other_player.health -= damage_dealt
        print(f"{self.name} attacked {other_player.name} and dealt {damage_dealt} damage.")

    def special_move(self, other_player):
        if self.special_move_available:
            damage_dealt = self.special_move_damage
            other_player.health -= damage_dealt
            print(f"{self.name} used a special move on {other_player.name} and dealt {damage_dealt} damage.")
            self.special_move_available = False
        else:
            print(f"{self.name}'s special move is not available.")

    def display_info(self):
        print(f"{self.name} - Health: {self.health}")

class Game:
    def __init__(self):
        self.players = []

    def add_player(self, player):
        self.players.append(player)

    def player_list(self):
        print("Current Players:")
        for player in self.players:
            player.display_info()

    def start_battle(self):
        if len(self.players) < 2:
            print("Need at least 2 players to start a battle.")
            return

        print("Battle Started!")
        while any(player.health > 0 for player in self.players):
            attacker = random.choice(self.players)
            defender = random.choice([player for player in self.players if player != attacker])

            # Randomly decide whether to use a special move or a regular attack
            if random.choice([True, False]):
                attacker.special_move(defender)
            else:
                attacker.attack(defender)

            self.player_list()

        print("Battle Ended!")

if __name__ == "__main__":
    game = Game()

    # Create players
    player1 = Player("Player 1")
    player2 = Player("Player 2")
    player3 = Player("Player 3")

    # Add players to the game
    game.add_player(player1)
    game.add_player(player2)
    game.add_player(player3)

    # Display player list
    game.player_list()

    # Start the battle
    game.start_battle()
import random

class Player:
    def __init__(self, name, health=100, damage=10):
        self.name = name
        self.health = health
        self.damage = damage
        self.special_move_damage = 20  # Extra damage for special move
        self.special_move_available = True

    def attack(self, other_player):
        damage_dealt = random.randint(1, self.damage)
        other_player.health -= damage_dealt
        print(f"{self.name} attacked {other_player.name} and dealt {damage_dealt} damage.")

    def special_move(self, other_player):
        if self.special_move_available:
            damage_dealt = self.special_move_damage
            other_player.health -= damage_dealt
            print(f"{self.name} used a special move on {other_player.name} and dealt {damage_dealt} damage.")
            self.special_move_available = False
        else:
            print(f"{self.name}'s special move is not available.")

    def display_info(self):
        print(f"{self.name} - Health: {self.health}")

class Game:
    def __init__(self):
        self.players = []

    def add_player(self, player):
        self.players.append(player)

    def player_list(self):
        print("Current Players:")
        for player in self.players:
            player.display_info()

    def start_battle(self):
        if len(self.players) < 2:
            print("Need at least 2 players to start a battle.")
            return

        print("Battle Started!")
        while any(player.health > 0 for player in self.players):
            attacker = random.choice(self.players)
            defender = random.choice([player for player in self.players if player != attacker])

            # Randomly decide whether to use a special move or a regular attack
            if random.choice([True, False]):
                attacker.special_move(defender)
            else:
                attacker.attack(defender)

            self.player_list()

        print("Battle Ended!")

if __name__ == "__main__":
    game = Game()

    # Create players
    player1 = Player("Player 1")
    player2 = Player("Player 2")
    player3 = Player("Player 3")

    # Add players to the game
    game.add_player(player1)
    game.add_player(player2)
    game.add_player(player3)

    # Display player list
    game.player_list()

    # Start the battle
    game.start_battle()
import random
import time

class Weapon:
    def __init__(self, name, damage):
        self.name = name
        self.damage = damage

class Demon:
    def __init__(self, name, damage):
        self.name = name
        self.damage = damage

class Player:
    def __init__(self, name, health=100, damage=10):
        self.name = name
        self.health = health
        self.damage = damage
        self.special_move_damage = 20
        self.special_move_available = True
        self.weapon = None
        self.demon = None

    def attack(self, other_player):
        damage_dealt = random.randint(1, self.damage)
        if self.weapon:
            damage_dealt += self.weapon.damage
        other_player.health -= damage_dealt
        print(f"{self.name} attacked {other_player.name} and dealt {damage_dealt} damage.")

    def special_move(self, other_player):
        if self.special_move_available:
            damage_dealt = self.special_move_damage
            if self.weapon:
                damage_dealt += self.weapon.damage
            other_player.health -= damage_dealt
            print(f"{self.name} used a special move on {other_player.name} and dealt {damage_dealt} damage.")
            self.special_move_available = False
        else:
            print(f"{self.name}'s special move is not available.")

    def use_ability(self):
        if self.weapon:
            print(f"{self.name} used {self.weapon.name} ability!")
            # Implement the ability logic here

    def summon_demon(self):
        if self.demon:
            print(f"{self.name} summoned {self.demon.name} for an attack!")
            # Implement the demon attack logic here

    def display_info(self):
        print(f"{self.name} - Health: {self.health}")

class Game:
    def __init__(self):
        self.players = []

    def add_player(self, player):
        self.players.append(player)

    def player_list(self):
        print("Current Players:")
        for player in self.players:
            player.display_info()

    def start_battle(self):
        if len(self.players) < 2:
            print("Need at least 2 players to start a battle.")
            return

        print("Battle Started!")
        while any(player.health > 0 for player in self.players):
            attacker = random.choice(self.players)
            defender = random.choice([player for player in self.players if player != attacker])

            # Randomly decide whether to use a special move, regular attack, or use ability
            action_choice = random.choice(["special_move", "attack", "ability"])
            if action_choice == "special_move":
                attacker.special_move(defender)
            elif action_choice == "attack":
                attacker.attack(defender)
            else:
                attacker.use_ability()

            # Demon summoning every 30 seconds
            if time.time() % 30 == 0:
                for player in self.players:
                    player.summon_demon()

            self.player_list()

        print("Battle Ended!")

if __name__ == "__main__":
    game = Game()

    # Create players with weapons and demons
    player1 = Player("Player 1")
    player1.weapon = Weapon("Sword", 5)
    player1.demon = Demon("Fire Demon", 15)

    player2 = Player("Player 2")
    player2.weapon = Weapon("Axe", 8)
    player2.demon = Demon("Ice Demon", 12)

    player3 = Player("Player 3")
    player3.weapon = Weapon("Bow", 7)
    player3.demon = Demon("Thunder Demon", 10)

    # Add players to the game
    game.add_player(player1)
    game.add_player(player2)
    game.add_player(player3)

    # Display player list
    game.player_list()

    # Start the battle
    game.start_battle()


import random
import time

class Weapon:
    def __init__(self, name, damage):
        self.name = name
        self.damage = damage

class Demon:
    def __init__(self, name, damage):
        self.name = name
        self.damage = damage

class Player:
    def __init__(self, name, health=100, damage=10):
        self.name = name
        self.health = health
        self.damage = damage
        self.special_move_damage = 20
        self.special_move_available = True
        self.weapon = None
        self.demon = None

    def attack(self, other_player):
        try:
            damage_dealt = random.randint(1, self.damage)
            if self.weapon:
                damage_dealt += self.weapon.damage
            other_player.health -= damage_dealt
            print(f"{self.name} attacked {other_player.name} and dealt {damage_dealt} damage.")
        except Exception as e:
            print(f"Error during attack: {e}")

    def special_move(self, other_player):
        try:
            if self.special_move_available:
                damage_dealt = self.special_move_damage
                if self.weapon:
                    damage_dealt += self.weapon.damage
                other_player.health -= damage_dealt
                print(f"{self.name} used a special move on {other_player.name} and dealt {damage_dealt} damage.")
                self.special_move_available = False
            else:
                print(f"{self.name}'s special move is not available.")
        except Exception as e:
            print(f"Error during special move: {e}")

    def use_ability(self):
        try:
            if self.weapon:
                print(f"{self.name} used {self.weapon.name} ability!")
                # Implement the ability logic here
        except Exception as e:
            print(f"Error during using ability: {e}")

    def summon_demon(self):
        try:
            if self.demon:
                print(f"{self.name} summoned {self.demon.name} for an attack!")
                # Implement the demon attack logic here
        except Exception as e:
            print(f"Error during demon summoning: {e}")

    def display_info(self):
        print(f"{self.name} - Health: {self.health}")

class Game:
    def __init__(self):
        self.players = []

    def add_player(self, player):
        try:
            self.players.append(player)
        except Exception as e:
            print(f"Error adding player: {e}")

    def player_list(self):
        try:
            print("Current Players:")
            for player in self.players:
                player.display_info()
        except Exception as e:
            print(f"Error displaying player list: {e}")

    def start_battle(self):
        try:
            if len(self.players) < 2:
                print("Need at least 2 players to start a battle.")
                return

            print("Battle Started!")
            while any(player.health > 0 for player in self.players):
                attacker = random.choice(self.players)
                defender = random.choice([player for player in self.players if player != attacker])

                # Randomly decide whether to use a special move, regular attack, or use ability
                action_choice = random.choice(["special_move", "attack", "ability"])
                if action_choice == "special_move":
                    attacker.special_move(defender)
                elif action_choice == "attack":
                    attacker.attack(defender)
                else:
                    attacker.use_ability()

                # Demon summoning every 30 seconds
                if time.time() % 30 == 0:
                    for player in self.players:
                        player.summon_demon()

                self.player_list()

            print("Battle Ended!")
        except Exception as e:
            print(f"Error during battle: {e}")

if __name__ == "__main__":
    try:
        game = Game()

        # Create players with weapons and demons
        player1 = Player("Player 1")
        player1.weapon = Weapon("Sword", 5)
        player1.demon = Demon("Fire Demon", 15)

        player2 = Player("Player 2")
        player2.weapon = Weapon("Axe", 8)
        player2.demon = Demon("Ice Demon", 12)

        player3 = Player("Player 3")
        player3.weapon = Weapon("Bow", 7)
        player3.demon = Demon("Thunder Demon", 10)

        # Add players to the game
        game.add_player(player1)
        game.add_player(player2)
        game.add_player(player3)

        # Display player list
        game.player_list()

        # Start the battle
        game.start_battle()
    except Exception as e:
        print(f"Error in main program: {e}")
class Player:
    def __init__(self, name, health=100, damage=10):
        self.name = name
        self.health = health
        self.damage = damage
        self.special_move_damage = 20
        self.special_move_available = True
        self.weapon = None
        self.demon = None

# ...

if __name__ == "__main__":
    try:
        # Create players with weapons and demons
        player1 = Player("Player 1")
        player1.weapon = Weapon("Sword", 5)
        player1.demon = Demon("Fire Demon", 15)

        player2 = Player("Player 2")
        player2.weapon = Weapon("Axe", 8)
        player2.demon = Demon("Ice Demon", 12)

        player3 = Player("Player 3")
        player3.weapon = Weapon("Bow", 7)
        player3.demon = Demon("Thunder Demon", 10)

        # Add players to the game
        game.add_player(player1)
        game.add_player(player2)
        game.add_player(player3)

        # Display player list
        game.player_list()

        # Start the battle
        game.start_battle()
    except Exception as e:
        print(f"Error in main program: {e}")
class Game:
    def __init__(self):
        self.players = []

# ...

if __name__ == "__main__":
    try:
        # ...

        # Access player at index 10 (if it doesn't exist)
        invalid_player = game.players[10]
    except IndexError as e:
        print(f"Index error: {e}")
    except Exception as e:
        print(f"Error in main program: {e}")
class Player:
    def __init__(self, name, health=100, damage=10):
        self.name = name
        self.health = health
        self.damage = damage
        self.special_move_damage = 20
        self.special_move_available = True
        self.weapon = None
        self.demon = None

# ...

if __name__ == "__main__":
    try:
        # ...

        # Access a non-existent attribute
        invalid_attribute = player1.invalid_attribute
    except AttributeError as e:
        print(f"Attribute error: {e}")
    except Exception as e:
        print(f"Error in main program: {e}")
