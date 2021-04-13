/*
   Transposition functions
*/

int transposeVert(int input, int dist) {
  int rowInd = input / 8;
  switch (rowInd % 2) {
    case 0:
      input = input + dist;
      break;
    case 1:
      input = input - dist;
      break;
  }
  return input;
}
int transposeHor(int input, int dist) {         //Negative dist = right Positive dist = left
  if (dist == 0) {
    return input;
  } else {
    int tempInput = input % 8;
    switch (tempInput) {
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

int transpose(int input, int vert, int hor) {
  return transposeHor(transposeVert(input, vert), hor);
}
