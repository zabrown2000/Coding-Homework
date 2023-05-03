public class FileStatsVisitor implements FileVisitor{
//using built in methods for each file type to get the required stats

    @Override
    public int visit(JpgFileDetails jpgFile) {
        System.out.printf("The picture %s has an average of %d bytes per pixel.%n", jpgFile.getName(),
                Math.round(jpgFile.getSize() / (double)(jpgFile.getHeight() * jpgFile.getWidth())));
        return 0;
    }
    @Override
    public int visit(Mp3FileDetails mp3File) {
        System.out.printf("The bitrate of %s is %d bytes per second.%n", mp3File.getName(),
                mp3File.getSize() / mp3File.getLengthSec());
        return 0;
    }
    @Override
    public int visit(PptxFileDetails pptxFile) {
        System.out.printf("The average slide size in Presentation %s is %d.%n", pptxFile.getName(),
                pptxFile.getSize() / pptxFile.getSlides());
        return 0;
    }
    @Override
    public int visit(TxtFileDetails txtFile) {
        System.out.printf("The file %s contains %d words.%n", txtFile.getName(), txtFile.getWords());
        return 0;
    }
    @Override
    public int visit(DocxFileDetails docxFile) {
        System.out.printf("The file %s has an average of %d words per page.%n", docxFile.getName(),
                docxFile.getWords() / docxFile.getPages());
        return 0;
    }
    @Override
    public int visit(DirectoryDetails directory) {
        for (FileDetails file : directory) {
            file.accept(this);
        }
        System.out.printf("Directory %s has %d files.%n", directory.getName(),
                directory.accept(new FileCountVisitor()));
        return 0;
    }
    @Override
    public int visit(HtmlFileDetails htmlFile) {
        System.out.printf("The file %s contains %d lines.%n", htmlFile.getName(), htmlFile.getLines());
        return 0;
    }

}
