// This holds some player information, like color and position.
// It also has some player methods for managing how a player moves.


class Player {

  color playerColor;
  int position;
  int score;


  Player(color _c, int _displaySize) {
    playerColor = _c;
    position = int(random(1,_displaySize));       // assign player to a random position within the buffer
  }

  // Move player based on keyboard input
  void move(int _direction) {
    position = position + _direction;
    
    if (position == -1) {
      position = displaySize - 1;
    } else if (position == displaySize) {
      position = 0;
    }
    
  }

}
