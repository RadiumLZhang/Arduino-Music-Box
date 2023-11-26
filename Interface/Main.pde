final int MAIN_PAGE = 0;
final int PIANO_PAGE = 1;
int currentPage = MAIN_PAGE;

void draw() {
  switch(currentPage) {
    case MAIN_PAGE:
      drawMainPage();
      break;
    case PIANO_PAGE:
      drawPianoPage();
      break;
  }
}
