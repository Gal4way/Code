class HaierTvFactory implements TvFactory {
    @Override
    public TvInterface producttv() {
        return new HaierTV();
    }
}