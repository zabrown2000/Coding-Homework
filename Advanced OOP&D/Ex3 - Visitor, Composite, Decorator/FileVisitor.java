/*Doing the standard visitor pattern*/

public interface FileVisitor {
    int visit(JpgFileDetails jpgFile);
    int visit(Mp3FileDetails mp3File);
    int visit(PptxFileDetails pptxFile);
    int visit(TxtFileDetails txtFile);
    int visit(DocxFileDetails docxFile);
    int visit(DirectoryDetails directory);
    int visit(HtmlFileDetails htmlFile);

}
