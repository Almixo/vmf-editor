# A valve-map-file parser/editor/replacer thing
Allows you to change any keyvalue ("something" "value") inside a .vmf file.
Doesn't break formatting.
Requires c++20.

Can be theoretically used for any other files that are written the same way (such as .vmt... didn't test, can't tell).

# Usage
exe file.extension "key" "oldvalue" "newvalue" =====> vmfupdater ba_maint.vmf "lightmapscale" "0" "2048"
