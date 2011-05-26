// To change UI component asychronously

Handler hRefresh = new Handler(){
	@Override
		public void handleMessage(Message msg) {
			switch(msg.what){
				case 0:
					/*Refresh UI*/
					btnEncodeOgg.setEnabled(true);
					break;
			}
		}
};

hRefresh.sendEmptyMessage(0);

// ------------------------------------------------------------------

private Handler handler = new Handler();

private Runnable updateTimer = new Runnable() {
	public void run() {
		// repeatedly update time
		handler.postDelayed(this, 1000);
		Long spentTime = System.currentTimeMillis() - startTime;
		Long minutes = spentTime/60000;
		Long seconds = (spentTime/1000)%60;
		tvTime.setText(minutes + ":" + String.format("%02d", seconds));
	}
};

// to stop
handler.removeCallbacks(updateTimer);
handler.postDelayed(updateTimer, 1000);

