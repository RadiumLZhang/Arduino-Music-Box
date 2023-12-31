final int MAIN_PAGE=0;
final int PIANO_PAGE=1;
final int UPLOAD_PAGE=2;
final int PLAYING_PAGE = 3;

int currentPage=MAIN_PAGE;

void draw() {
  switch(currentPage) {
  case MAIN_PAGE:
    drawMainPage();
    break;
  case PIANO_PAGE:
    drawPianoPage();
    break;
  case UPLOAD_PAGE:
    drawUploadPage();
    break;

  case PLAYING_PAGE:
    drawPlayingPage();
    break;
  }

  // is song is playing
  if (song != null && song.isPlaying()) {
    // draw the spectrum
    analyzeAudioAndExtractFrequencies();
  }
}
