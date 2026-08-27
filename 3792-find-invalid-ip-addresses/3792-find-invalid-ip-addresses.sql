# Write your MySQL query statement below
with temp as (
    select ip,case
        when exists(select 1 
             FROM JSON_TABLE(
                    CONCAT('["', REPLACE(ip, '.', '","'), '"]'),
                    '$[*]' COLUMNS (
                        value VARCHAR(10) PATH '$'
                    )
                ) s
            where CAST(s.value AS unsigned)>255 or (s.value like '0%' and s.value!='0') or s.value regexp '[^0-9]'
        ) or (length(ip)-length(replace(ip,'.',''))) !=3 then true else false END as status
    from logs
)

select ip,count(*) as invalid_count
from temp
where status=true
group by ip
order by 2,1 DESC