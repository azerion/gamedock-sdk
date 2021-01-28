# Cascade Select
This page demonstrates GDC's `CascadeSelect` fields.

The CascadeSelectField is a SelectField that it's options change dynamicaly based on values of other fields.
A basic example is when you have to choose a Platform and a version for that platform - in that case we would like to show only the versions that are available 
for this platform.

The choices may also be based on multiple fields or even fetched from the backend through an AJAX request 
- in the example, the `fish` and `bird` options fetch their animals list from the backend.
