/*
   Raine Bradley
   Emoji Mask
   Last Modified: 4.27.21
   transpose.h contains the transposition functions necessary for the creation of each Emoji Mask design.
*/

/*
   This function will wrap around the LED strip. If the shift will move the LED to a new column or a number < 0 or > 255 it will instead move it to the opposite end of the current column.
   int input = original LED # that the vertical shift will be relative to.
   int dist = the number of vertical steps (positive or negative) required to be taken.
   return the LED # of the new location
*/
int transposeVert(int input, int dist) {  //Negative dist = down Positive dist = up

  /*
     colInd will be used to determine the column of the given input. Depending on the column # vertical shifts will require a positive or negative equation.
     rowInd is used to determine if the function must wrap around the LED. If rowInd = 0 or 7 then the shift may need to wrap around.
  */
  int colInd = input / 8, rowInd = input % 8;

  switch (colInd % 2) {
    case 0:
      if (rowInd + dist < 0) {
        Serial.println("Begin Wraping.");
        while (rowInd != 0) {
          input --;
          dist ++;
          rowInd = input % 8;
        }
        input = input + 7;
        dist ++;
      }
      if (rowInd + dist > 7) {
        Serial.println("Begin Wraping.");
        while (rowInd != 7) {
          input ++;
          dist --;
          rowInd = input % 8;
        }
        input = input - 7;
        dist --;
      }
      input = input + dist;
      break;

    case 1:
      if (rowInd - dist < 0) {
        while (rowInd != 0) {
          input --;
          dist --;
          rowInd = input % 8;
        }
        input = input + 7;
        dist --;
      }
      if (rowInd - dist > 7) {
        while (rowInd != 7) {
          input ++;
          dist ++;
          rowInd = input % 8;

        }
        input = input - 7;
        dist ++;
      }
      input = input - dist;
      break;
  }
  return input;
}

/*
   This function will wrap around the LED strip. If the shift will move the LED to a number < 0 or > 255 it will instead wrap around to the far end of the strip.
   int input = original LED # that the vertical shift will be relative to.
   int dist = the number of Horizontal steps (positive or negative) required to be taken.
   return the LED # of the new location
*/
int transposeHor(int input, int dist) {         //Negative dist = right Positive dist = left
  if (dist == 0) {
    return input;
  } else {
    int rowInd = input % 8;
    if (input < 8 && dist < 0) {
      Serial.print("input < 8 ");
      Serial.print("input = ");
      Serial.print(input);
      Serial.println();
      input = 255 - rowInd;
      Serial.print("newInput = ");
      Serial.print(input);
      Serial.println();
      rowInd = input % 8;
      dist++;
      Serial.print("Dist = ");
      Serial.print(dist);
      Serial.println();
      Serial.print("return transposeHor(");
      Serial.print(input);
      Serial.print(", ");
      Serial.print(dist);
      Serial.print(");");
      Serial.println();
      return transposeHor(input, dist);
    } else {
      if (input > 247 && dist > 0) {
        Serial.print("input > 247 ");
        Serial.print("input = ");
        Serial.print(input);
        Serial.println();
        input = 0 + (7 - rowInd);
        Serial.print("newInput = ");
        Serial.print(input);
        Serial.println();
        rowInd = input % 8;
        dist--;
        Serial.print("Dist = ");
        Serial.print(dist);
        Serial.println();
        Serial.print("return transposeHor(");
        Serial.print(input);
        Serial.print(", ");
        Serial.print(dist);
        Serial.print(");");
        Serial.println();
        return transposeHor(input, dist);
      } else {
        switch (rowInd) {
          case 0:
            if (dist < 0) {
              input = input - 1;
            } else {
              input = input + 15;
            }
            break;
          case 1:
            if (dist < 0) {
              input = input - 3;
            } else {
              input = input + 13;
            }
            break;
          case 2:
            if (dist < 0) {
              input = input - 5;
            } else {
              input = input + 11;
            }
            break;
          case 3:
            if (dist < 0) {
              input = input - 7;
            } else {
              input = input + 9;
            }
            break;
          case 4:
            if (dist < 0) {
              input = input - 9;
            } else {
              input = input + 7;
            }
            break;
          case 5:
            if (dist < 0) {
              input = input - 11;
            } else {
              input = input + 5;
            }
            break;
          case 6:
            if (dist < 0) {
              input = input - 13;
            } else {
              input = input + 3;
            }
            break;
          case 7:
            if (dist < 0) {
              input = input - 15;
            } else {
              input = input + 1;
            }
            break;
        }
        if (dist > 0) {
          dist--;
        } else {
          dist++;
        }
        return transposeHor(input, dist);
      }
    }
  }
}
/*
   int input = original LED # that the vertical shift will be relative to.
   int vert = the number of vertical steps (positive or negative) required to be taken.
   return recurzive call of the horizontal and vertical transpostion functions. Will return the new desired LED #.

*/
int transpose(int input, int vert, int hor) {
  return transposeHor(transposeVert(input, vert), hor);
}
