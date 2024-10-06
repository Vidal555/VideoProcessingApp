# Video Processing Application

## תיאור
אפליקציית עיבוד וידאו המבוססת על OpenCV. האפליקציה מאפשרת חיתוך, שינוי גודל, סיבוב, הוספת טקסט ופילטרים על קובצי וידאו.

## דרישות
- OpenCV
- GStreamer (שימוש לא הושלם עדיין)
- CMake

## התקנה
1. **התקנת OpenCV**:
   - יש להוריד ולהתקין את OpenCV למערכת שלך.
   - יש להגדיר את הנתיב ל-OpenCV במערכת.

2. **התקנת GStreamer**:
   - יש להוריד ולהתקין את GStreamer.

3. **התקנת CMake**:
   - יש להוריד ולהתקין את CMake.

## איך להריץ
1. **בניית הפרויקט**:
   ```bash
   mkdir build
   cd build
   cmake ..
   cmake --build . --config Release

   ./Release/VideoProcessingApp.exe "<נתיב לקובץ הווידאו>"
"# VideoProcessingApp" 
